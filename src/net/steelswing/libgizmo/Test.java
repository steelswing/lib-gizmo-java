/*
 * Ну вы же понимаете, что код здесь только мой?
 * Well, you do understand that the code here is only mine?
 */

package net.steelswing.libgizmo;

import java.io.File;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import net.steelswing.libgizmo.glu.GLU;
import org.lwjgl.BufferUtils;
import org.lwjgl.glfw.GLFW;
import org.lwjgl.glfw.GLFWErrorCallback;
import org.lwjgl.glfw.GLFWVidMode;
import org.lwjgl.opengl.GL;
import org.lwjgl.opengl.GL21;
import org.lwjgl.system.MemoryStack;

/**
 * File: Test.java
 * Created on 15 авг. 2023 г., 07:40:31
 *
 * @author LWJGL2
 */
public class Test {

    private long window;
    private int width, height;
    private LibGizmo gizmo;
    private int mouseX, mouseY;

    private static FloatBuffer objectMatrix = BufferUtils.createFloatBuffer(16);

    static {
        objectMatrix.put(new float[]{
            1.f, 0.f, 0.f, 0.f,
            0.f, 1.f, 0.f, 0.f,
            0.f, 0.f, 1.f, 0.f,
            0.f, 0.f, 0.f, 1.f});
        objectMatrix.flip();
    }

    public void run() {
        init();
        loop();

        // Free the window callbacks and destroy the window
        GLFW.glfwDestroyWindow(window);

        // Terminate GLFW and free the error callback
        GLFW.glfwTerminate();
        GLFW.glfwSetErrorCallback(null).free();
    }

    private void init() {
        // Setup an error callback. The default implementation
        // will print the error message in System.err.
        GLFWErrorCallback.createPrint(System.err).set();

        // Initialize GLFW. Most GLFW functions will not work before doing this.
        if (!GLFW.glfwInit()) {
            throw new IllegalStateException("Unable to initialize GLFW");
        }

        // Configure GLFW
        GLFW.glfwDefaultWindowHints(); // optional, the current window hints are already the default
        GLFW.glfwWindowHint(GLFW.GLFW_VISIBLE, GLFW.GLFW_FALSE); // the window will stay hidden after creation
        GLFW.glfwWindowHint(GLFW.GLFW_RESIZABLE, GLFW.GLFW_TRUE); // the window will be resizable

        // Create the window
        window = GLFW.glfwCreateWindow(1280, 720, "Hello World!", 0, 0);
        if (window == 0) {
            throw new RuntimeException("Failed to create the GLFW window");
        }

        // Setup a key callback. It will be called every time a key is pressed, repeated or released.
        GLFW.glfwSetKeyCallback(window, (window, key, scancode, action, mods) -> {
            if (key == GLFW.GLFW_KEY_ESCAPE && action == GLFW.GLFW_RELEASE) {
                GLFW.glfwSetWindowShouldClose(window, true); // We will detect this in the rendering loop
            }
        });

        // Get the thread stack and push a new frame
        try (MemoryStack stack = MemoryStack.stackPush()) {
            IntBuffer pWidth = stack.mallocInt(1); // int*
            IntBuffer pHeight = stack.mallocInt(1); // int*

            // Get the window size passed to glfwCreateWindow
            GLFW.glfwGetWindowSize(window, pWidth, pHeight);

            // Get the resolution of the primary monitor
            GLFWVidMode vidmode = GLFW.glfwGetVideoMode(GLFW.glfwGetPrimaryMonitor());

            // Center the window
            GLFW.glfwSetWindowPos(
                    window,
                    (vidmode.width() - pWidth.get(0)) / 2,
                    (vidmode.height() - pHeight.get(0)) / 2
            );
        } // the stack frame is popped automatically

        // Make the OpenGL context current
        GLFW.glfwMakeContextCurrent(window);
        // Enable v-sync
        GLFW.glfwSwapInterval(1);

        // Make the window visible
        GLFW.glfwShowWindow(window);
    }

    private void loop() {
        // This line is critical for LWJGL's interoperation with GLFW's
        // OpenGL context, or any context that is managed externally.
        // LWJGL detects the context that is current in the current thread,
        // creates the GLCapabilities instance and makes the OpenGL
        // bindings available for use.
        GL.createCapabilities();

        // Set the clear color
        GL21.glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
        try (MemoryStack stack = MemoryStack.stackPush()) {
            IntBuffer pWidth = stack.mallocInt(1); // int*
            IntBuffer pHeight = stack.mallocInt(1); // int*
            GLFW.glfwGetWindowSize(window, pWidth, pHeight);
            width = pWidth.get(0);
            height = pHeight.get(0);
        }

        // Run the rendering loop until the user has attempted to close
        // the window or has pressed the ESCAPE key.
        glInit();
        while (!GLFW.glfwWindowShouldClose(window)) {

            try (MemoryStack stack = MemoryStack.stackPush()) {
                IntBuffer pWidth = stack.mallocInt(1); // int*
                IntBuffer pHeight = stack.mallocInt(1); // int*
                GLFW.glfwGetWindowSize(window, pWidth, pHeight);
                width = pWidth.get(0);
                height = pHeight.get(0);
            }

            glRender();
            GLFW.glfwSwapBuffers(window); // swap the color buffers

            // Poll for window events. The key callback above will only be
            // invoked during this call.
            GLFW.glfwPollEvents();
        }
    }

    private void glInit() {
        GL21.glEnable(GL21.GL_TEXTURE_2D); // Enable Texture Mapping ( NEW )
        GL21.glShadeModel(GL21.GL_SMOOTH); // Enable Smooth Shading
        GL21.glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // Black Background
        GL21.glClearDepth(1.0f); // Depth Buffer Setup
        GL21.glEnable(GL21.GL_DEPTH_TEST); // Enables Depth Testing
        GL21.glDepthFunc(GL21.GL_LEQUAL); // The Type Of Depth Testing To Do
        GL21.glHint(GL21.GL_PERSPECTIVE_CORRECTION_HINT, GL21.GL_NICEST); // Really Nice Perspective Calculations
        GL21.glDepthMask(true);

        gizmo = LibGizmo.create(GizmoType.GIZMO_SCALE);
        gizmo.setEditMatrix(objectMatrix);
        gizmo.setScreenDimension(width, height);
        gizmo.setDisplayScale(2);
        System.out.println("aga");

        GLFW.glfwSetCursorPosCallback(window, (window, xpos, ypos) -> {
            mouseX = (int) xpos;
            mouseY = (int) ypos;

            gizmo.onMouseMove(mouseX, mouseY);
        });
        GLFW.glfwSetMouseButtonCallback(window, (window, button, action, mods) -> {
            if (action == GLFW.GLFW_PRESS) {
                gizmo.onMouseDown(mouseX, mouseY);

            }
            if (action == GLFW.GLFW_RELEASE) {
                gizmo.onMouseUp(mouseX, mouseY);
            }
        });
    }

    public void resize() { // Prevent A Divide By Zero By
        GL21.glViewport(0, 0, width, height); // Reset The Current Viewport

        GL21.glMatrixMode(GL21.GL_PROJECTION); // Select The Projection Matrix
        GL21.glLoadIdentity(); // Reset The Projection Matrix

        // Calculate The Aspect Ratio Of The Window
        GLU.gluPerspective(45.0f, width / (float) height, 0.1f, 100.0f);

        GL21.glMatrixMode(GL21.GL_MODELVIEW); // Select The Modelview Matrix
        GL21.glLoadIdentity(); // Reset The Modelview Matrix
        GLU.gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);

        gizmo.setScreenDimension(width, height);
    }
    private static final int CAM_DISTANCE = 8;
    private static final float CAM_Y_ANGLE = 165.f / 180.f * (float) Math.PI;
    private static final float CAM_X_ANGLE = 32.f / 180.f * (float) Math.PI;
    private static final float FLT_EPSILON = 1.19209290E-07f;


    private static final float[] INPUT_CAMERA_VIEW = {
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f
    };

    private static float[] perspective(float fovY, float aspect, float near, float far) {
        float ymax, xmax;
        ymax = (float) (near * Math.tan(fovY * Math.PI / 180.0f));
        xmax = ymax * aspect;
        return frustum(-xmax, xmax, -ymax, ymax, near, far);
    }

    private static float[] frustum(float left, float right, float bottom, float top, float near, float far) {
        float[] r = new float[16];
        float temp = 2.0f * near;
        float temp2 = right - left;
        float temp3 = top - bottom;
        float temp4 = far - near;
        r[0] = temp / temp2;
        r[1] = 0.0f;
        r[2] = 0.0f;
        r[3] = 0.0f;
        r[4] = 0.0f;
        r[5] = temp / temp3;
        r[6] = 0.0f;
        r[7] = 0.0f;
        r[8] = (right + left) / temp2;
        r[9] = (top + bottom) / temp3;
        r[10] = (-far - near) / temp4;
        r[11] = -1.0f;
        r[12] = 0.0f;
        r[13] = 0.0f;
        r[14] = (-temp * far) / temp4;
        r[15] = 0.0f;
        return r;
    }

    private static float[] cross(float[] a, float[] b) {
        float[] r = new float[3];
        r[0] = a[1] * b[2] - a[2] * b[1];
        r[1] = a[2] * b[0] - a[0] * b[2];
        r[2] = a[0] * b[1] - a[1] * b[0];
        return r;
    }

    private static float dot(float[] a, float[] b) {
        return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    }

    private static float[] normalize(float[] a) {
        float[] r = new float[3];
        float il = (float) (1.f / (Math.sqrt(dot(a, a)) + FLT_EPSILON));
        r[0] = a[0] * il;
        r[1] = a[1] * il;
        r[2] = a[2] * il;
        return r;
    }

    private static void lookAt(float[] eye, float[] at, float[] up, float[] m16) {
        float[] x;
        float[] y;
        float[] z;
        float[] tmp = new float[3];

        tmp[0] = eye[0] - at[0];
        tmp[1] = eye[1] - at[1];
        tmp[2] = eye[2] - at[2];
        z = normalize(tmp);
        y = normalize(up);

        tmp = cross(y, z);
        x = normalize(tmp);

        tmp = cross(z, x);
        y = normalize(tmp);

        m16[0] = x[0];
        m16[1] = y[0];
        m16[2] = z[0];
        m16[3] = 0.0f;
        m16[4] = x[1];
        m16[5] = y[1];
        m16[6] = z[1];
        m16[7] = 0.0f;
        m16[8] = x[2];
        m16[9] = y[2];
        m16[10] = z[2];
        m16[11] = 0.0f;
        m16[12] = -dot(x, eye);
        m16[13] = -dot(y, eye);
        m16[14] = -dot(z, eye);
        m16[15] = 1.0f;
    }

    private void glRender() {
        resize();
        GL21.glClearColor(0, 0, 0, 1);
        GL21.glClear(GL21.GL_COLOR_BUFFER_BIT | GL21.GL_DEPTH_BUFFER_BIT); // clear the framebuffer

        FloatBuffer viewMat = BufferUtils.createFloatBuffer(16);
        {
            float[] eye = new float[]{
                (float) (Math.cos(CAM_Y_ANGLE) * Math.cos(CAM_X_ANGLE) * CAM_DISTANCE),
                (float) (Math.sin(CAM_X_ANGLE) * CAM_DISTANCE),
                (float) (Math.sin(CAM_Y_ANGLE) * Math.cos(CAM_X_ANGLE) * CAM_DISTANCE)
            };
            float[] at = new float[]{0.f, 0.f, 0.f};
            float[] up = new float[]{0.f, 1.f, 0.f};
            lookAt(eye, at, up, INPUT_CAMERA_VIEW);
            viewMat.put(INPUT_CAMERA_VIEW);
            viewMat.flip();
        }

        FloatBuffer projMat = BufferUtils.createFloatBuffer(16);
        {
            float[] cameraProjection = perspective(27, width / (float) height, 0.1f, 100f);
            projMat.put(cameraProjection);
            projMat.flip();
        }

        GL21.glMatrixMode(GL21.GL_PROJECTION);
        GL21.glLoadIdentity();
        GL21.glLoadMatrixf(projMat);
        GL21.glMatrixMode(GL21.GL_MODELVIEW);
        GL21.glLoadIdentity();
        GL21.glLoadMatrixf(viewMat);

        GL21.glPushMatrix();
        GL21.glMultMatrixf(objectMatrix);
//        GL21.glScalef(50, 50, 50);
        GL21.glColor4f(0.5f, 0.5f, 0.5f, 1.f);
        GL21.glCullFace(GL21.GL_CW);
        GL21.glEnable(GL21.GL_CULL_FACE);
        GL21.glBegin(GL21.GL_QUADS);
        // Front Face
        GL21.glColor4f(0.6f, 0.6f, 0.6f, 1.f);
        GL21.glTexCoord2f(0.0f, 0.0f);
        GL21.glVertex3f(-1.0f, -1.0f, 1.0f);
        GL21.glColor4f(0.6f, 0.6f, 0.6f, 1.f);
        GL21.glTexCoord2f(1.0f, 0.0f);
        GL21.glVertex3f(1.0f, -1.0f, 1.0f);
        GL21.glColor4f(0.6f, 0.6f, 0.6f, 1.f);
        GL21.glTexCoord2f(1.0f, 1.0f);
        GL21.glVertex3f(1.0f, 1.0f, 1.0f);
        GL21.glColor4f(0.6f, 0.6f, 0.6f, 1.f);
        GL21.glTexCoord2f(0.0f, 1.0f);
        GL21.glVertex3f(-1.0f, 1.0f, 1.0f);
        // Back Face
        GL21.glColor4f(0.5f, 0.5f, 0.5f, 1.f);
        GL21.glTexCoord2f(1.0f, 0.0f);
        GL21.glVertex3f(-1.0f, -1.0f, -1.0f);
        GL21.glColor4f(0.5f, 0.5f, 0.5f, 1.f);
        GL21.glTexCoord2f(1.0f, 1.0f);
        GL21.glVertex3f(-1.0f, 1.0f, -1.0f);
        GL21.glColor4f(0.5f, 0.5f, 0.5f, 1.f);
        GL21.glTexCoord2f(0.0f, 1.0f);
        GL21.glVertex3f(1.0f, 1.0f, -1.0f);
        GL21.glColor4f(0.5f, 0.5f, 0.5f, 1.f);
        GL21.glTexCoord2f(0.0f, 0.0f);
        GL21.glVertex3f(1.0f, -1.0f, -1.0f);
        // Top Face
        GL21.glColor4f(0.4f, 0.4f, 0.4f, 1.f);
        GL21.glTexCoord2f(0.0f, 1.0f);
        GL21.glVertex3f(-1.0f, 1.0f, -1.0f);
        GL21.glColor4f(0.4f, 0.4f, 0.4f, 1.f);
        GL21.glTexCoord2f(0.0f, 0.0f);
        GL21.glVertex3f(-1.0f, 1.0f, 1.0f);
        GL21.glColor4f(0.4f, 0.4f, 0.4f, 1.f);
        GL21.glTexCoord2f(1.0f, 0.0f);
        GL21.glVertex3f(1.0f, 1.0f, 1.0f);
        GL21.glColor4f(0.4f, 0.4f, 0.4f, 1.f);
        GL21.glTexCoord2f(1.0f, 1.0f);
        GL21.glVertex3f(1.0f, 1.0f, -1.0f);
        // Bottom Face
        GL21.glColor4f(0.6f, 0.6f, 0.6f, 1.f);
        GL21.glTexCoord2f(1.0f, 1.0f);
        GL21.glVertex3f(-1.0f, -1.0f, -1.0f);
        GL21.glColor4f(0.6f, 0.6f, 0.6f, 1.f);
        GL21.glTexCoord2f(0.0f, 1.0f);
        GL21.glVertex3f(1.0f, -1.0f, -1.0f);
        GL21.glColor4f(0.6f, 0.6f, 0.6f, 1.f);
        GL21.glTexCoord2f(0.0f, 0.0f);
        GL21.glVertex3f(1.0f, -1.0f, 1.0f);
        GL21.glColor4f(0.6f, 0.6f, 0.6f, 1.f);
        GL21.glTexCoord2f(1.0f, 0.0f);
        GL21.glVertex3f(-1.0f, -1.0f, 1.0f);
        // Right face
        GL21.glColor4f(0.5f, 0.5f, 0.5f, 1.f);
        GL21.glTexCoord2f(1.0f, 0.0f);
        GL21.glVertex3f(1.0f, -1.0f, -1.0f);
        GL21.glColor4f(0.5f, 0.5f, 0.5f, 1.f);
        GL21.glTexCoord2f(1.0f, 1.0f);
        GL21.glVertex3f(1.0f, 1.0f, -1.0f);
        GL21.glColor4f(0.5f, 0.5f, 0.5f, 1.f);
        GL21.glTexCoord2f(0.0f, 1.0f);
        GL21.glVertex3f(1.0f, 1.0f, 1.0f);
        GL21.glColor4f(0.5f, 0.5f, 0.5f, 1.f);
        GL21.glTexCoord2f(0.0f, 0.0f);
        GL21.glVertex3f(1.0f, -1.0f, 1.0f);
        // Left Face
        GL21.glColor4f(0.4f, 0.4f, 0.4f, 1.f);
        GL21.glTexCoord2f(0.0f, 0.0f);
        GL21.glVertex3f(-1.0f, -1.0f, -1.0f);
        GL21.glColor4f(0.4f, 0.4f, 0.4f, 1.f);
        GL21.glTexCoord2f(1.0f, 0.0f);
        GL21.glVertex3f(-1.0f, -1.0f, 1.0f);
        GL21.glColor4f(0.4f, 0.4f, 0.4f, 1.f);
        GL21.glTexCoord2f(1.0f, 1.0f);
        GL21.glVertex3f(-1.0f, 1.0f, 1.0f);
        GL21.glColor4f(0.4f, 0.4f, 0.4f, 1.f);
        GL21.glTexCoord2f(0.0f, 1.0f);
        GL21.glVertex3f(-1.0f, 1.0f, -1.0f);
        GL21.glEnd();
        GL21.glPopMatrix();

        gizmo.setCameraMatrix(viewMat, projMat);
        gizmo.draw();
    }

    public static void main(String[] args) throws Throwable {
        System.load(new File("libLibGizmo.dll").getAbsolutePath());
        new Test().run();
    }

}

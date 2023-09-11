/*
 * Ну вы же понимаете, что код здесь только мой?
 * Well, you do understand that the code here is only mine?
 */

package net.steelswing.libgizmo;

import static net.steelswing.libgizmo.tvector3.*;
import org.lwjgl.opengl.GL21;

/**
 * File: LibGizmoRenderer.java
 * Created on 12 сент. 2023 г., 01:45:47
 *
 * @author LWJGL2
 */
public class LibGizmoRenderer {

    public static final float ZPI = 3.14159265358979323846f;
    public static final float PI_MUL_2 = 6.28318530717958647692f;
    public static final float PI_DIV_2 = 1.57079632679489655800f;
    public static final float PI_DIV_4 = 0.78539816339744827900f;
    public static final float INV_PI = 0.31830988618379069122f;
    public static final float DEGTORAD = 0.01745329251994329547f;
    public static final float RADTODEG = 57.29577951308232286465f;
    public static final float SQRT2 = 1.41421356237309504880f;
    public static final float SQRT3 = 1.73205080756887729352f;

    public static float cos(float a) {
        return (float) Math.cos(a);
    }

    public static float sin(float a) {
        return (float) Math.sin(a);
    }

    public static void DrawCircle(final tvector3 orig, float r, float g, float b, final tvector3 vtx, final tvector3 vty) {
        GL21.glDisable(GL21.GL_DEPTH_TEST);
        GL21.glDisable(GL21.GL_LIGHTING);
        GL21.glColor4f(r, g, b, 1);

        GL21.glBegin(GL21.GL_LINE_LOOP);
        for (int i = 0; i < 50; i++) {
            tvector3 vt;
            vt = mul(vtx, cos((2 * ZPI / 50) * i));
            vt.add(mul(vty, sin((2 * ZPI / 50) * i)));
            vt.add(orig);
            GL21.glVertex3f(vt.x, vt.y, vt.z);
        }
        GL21.glEnd();

    }

    public static void DrawCircleHalf(final tvector3 orig, float r, float g, float b, final tvector3 vtx, final tvector3 vty, tplane camPlan) {
        GL21.glDisable(GL21.GL_DEPTH_TEST);
        GL21.glDisable(GL21.GL_LIGHTING);
        GL21.glColor4f(r, g, b, 1);

        GL21.glBegin(GL21.GL_LINE_STRIP);
        for (int i = 0; i < 30; i++) {
            tvector3 vt;
            vt = mul(vtx, cos((ZPI / 30) * i));
            vt.add(mul(vty, sin((ZPI / 30) * i)));
            vt.add(orig);
            if (camPlan.DotNormal(vt) > 0) {
                GL21.glVertex3f(vt.x, vt.y, vt.z);
            }
        }
        GL21.glEnd();

    }

    public static void DrawAxis(final tvector3 orig, final tvector3 axis, final tvector3 vtx, final tvector3 vty, float fct, float fct2, final tvector4 col) {

        GL21.glDisable(GL21.GL_DEPTH_TEST);
        GL21.glDisable(GL21.GL_LIGHTING);
        GL21.glColor4f(col.x, col.y, col.z, col.w);
        GL21.glBegin(GL21.GL_LINES);
        GL21.glVertex3f(orig.x, orig.y, orig.z);
        GL21.glVertex3f(orig.x + axis.x, orig.y + axis.y, orig.z + axis.z);
        GL21.glEnd();

        GL21.glBegin(GL21.GL_TRIANGLE_FAN);
        for (int i = 0; i <= 30; i++) {
            tvector3 pt;
            pt = mul(vtx, cos(((2 * ZPI) / 30.0f) * i) * fct);
            pt.add(mul(vty, sin(((2 * ZPI) / 30.0f) * i) * fct));
            pt.add(mul(axis, fct2));
            pt.add(orig);
            GL21.glVertex3f(pt.x, pt.y, pt.z);
            pt = mul(vtx, cos(((2 * ZPI) / 30.0f) * (i + 1)) * fct);
            pt.add(mul(vty, sin(((2 * ZPI) / 30.0f) * (i + 1)) * fct));
            pt.add(mul(axis, fct2));
            pt.add(orig);
            GL21.glVertex3f(pt.x, pt.y, pt.z);
            GL21.glVertex3f(orig.x + axis.x, orig.y + axis.y, orig.z + axis.z);

        }
        GL21.glEnd();

    }

    public static void DrawCamem(final tvector3 orig, final tvector3 vtx, final tvector3 vty, float ng) {

        GL21.glDisable(GL21.GL_DEPTH_TEST);
        GL21.glDisable(GL21.GL_LIGHTING);
        int i = 0;
        GL21.glEnable(GL21.GL_BLEND);
        GL21.glBlendFunc(GL21.GL_SRC_ALPHA, GL21.GL_ONE_MINUS_SRC_ALPHA);

        GL21.glDisable(GL21.GL_CULL_FACE);

        GL21.glColor4f(1, 1, 0, 0.5f);
        GL21.glBegin(GL21.GL_TRIANGLE_FAN);
        GL21.glVertex3f(orig.x, orig.y, orig.z);
        for (i = 0; i <= 50; i++) {
            tvector3 vt;
            vt = mul(vtx, cos(((ng) / 50) * i));
            vt.add(mul(vty, sin(((ng) / 50) * i)));
            vt.add(orig);
            GL21.glVertex3f(vt.x, vt.y, vt.z);
        }
        GL21.glEnd();

        GL21.glDisable(GL21.GL_BLEND);

        GL21.glColor4f(1, 1, 0.2f, 1);
        GL21.glBegin(GL21.GL_LINE_LOOP);

        GL21.glVertex3f(orig.x, orig.y, orig.z);
        for (i = 0; i <= 50; i++) {
            tvector3 vt;
            vt = mul(vtx, cos(((ng) / 50) * i));
            vt.add(mul(vty, sin(((ng) / 50) * i)));
            vt.add(orig);
            GL21.glVertex3f(vt.x, vt.y, vt.z);
        }

        GL21.glEnd();

    }

    public static void DrawQuad(final tvector3 orig, float size, boolean bSelected, final tvector3 axisU, final tvector3 axisV) {

        GL21.glDisable(GL21.GL_DEPTH_TEST);
        GL21.glDisable(GL21.GL_LIGHTING);
        GL21.glEnable(GL21.GL_BLEND);
        GL21.glBlendFunc(GL21.GL_SRC_ALPHA, GL21.GL_ONE_MINUS_SRC_ALPHA);

        GL21.glDisable(GL21.GL_CULL_FACE);

        tvector3 pts[] = new tvector3[]{new tvector3(), new tvector3(), new tvector3(), new tvector3()};
        pts[0] = orig;
        pts[1] = add(orig, mul(axisU, size));
        pts[2] = add(orig, mul(add(axisU, axisV), size));
        pts[3] = add(orig, mul(axisV, size));

        if (!bSelected) {
            GL21.glColor4f(1, 1, 0, 0.5f);
        } else {
            GL21.glColor4f(1, 1, 1, 0.6f);
        }

        GL21.glBegin(GL21.GL_QUADS);
        GL21.glVertex3f(pts[0].x, pts[0].y, pts[0].z);
        GL21.glVertex3f(pts[1].x, pts[1].y, pts[1].z);
        GL21.glVertex3f(pts[2].x, pts[2].y, pts[2].z);
        GL21.glVertex3f(pts[3].x, pts[3].y, pts[3].z);
        GL21.glEnd();

        if (!bSelected) {
            GL21.glColor4f(1, 1, 0.2f, 1);
        } else {
            GL21.glColor4f(1, 1, 1, 0.6f);
        }

        GL21.glBegin(GL21.GL_LINE_STRIP);
        GL21.glVertex3f(pts[0].x, pts[0].y, pts[0].z);
        GL21.glVertex3f(pts[1].x, pts[1].y, pts[1].z);
        GL21.glVertex3f(pts[2].x, pts[2].y, pts[2].z);
        GL21.glVertex3f(pts[3].x, pts[3].y, pts[3].z);
        GL21.glEnd();

        GL21.glDisable(GL21.GL_BLEND);

    }

    public static void DrawTri(final tvector3 orig, float size, boolean bSelected, final tvector3 axisU, final tvector3 axisV) {

        GL21.glDisable(GL21.GL_DEPTH_TEST);
        GL21.glDisable(GL21.GL_LIGHTING);
        GL21.glEnable(GL21.GL_BLEND);
        GL21.glBlendFunc(GL21.GL_SRC_ALPHA, GL21.GL_ONE_MINUS_SRC_ALPHA);

        GL21.glDisable(GL21.GL_CULL_FACE);

        tvector3 pts[] = new tvector3[]{new tvector3(), new tvector3(), new tvector3(), new tvector3()};
        pts[0] = orig;

        pts[1] = (axisU);
        pts[2] = (axisV);

        pts[1].mul(size);
        pts[2].mul(size);
        pts[1].add(orig);
        pts[2].add(orig);

        if (!bSelected) {
            GL21.glColor4f(1, 1, 0, 0.5f);
        } else {
            GL21.glColor4f(1, 1, 1, 0.6f);
        }

        GL21.glBegin(GL21.GL_TRIANGLES);
        GL21.glVertex3f(pts[0].x, pts[0].y, pts[0].z);
        GL21.glVertex3f(pts[1].x, pts[1].y, pts[1].z);
        GL21.glVertex3f(pts[2].x, pts[2].y, pts[2].z);
        GL21.glVertex3f(pts[3].x, pts[3].y, pts[3].z);
        GL21.glEnd();

        if (!bSelected) {
            GL21.glColor4f(1, 1, 0.2f, 1);
        } else {
            GL21.glColor4f(1, 1, 1, 0.6f);
        }

        GL21.glBegin(GL21.GL_LINE_STRIP);
        GL21.glVertex3f(pts[0].x, pts[0].y, pts[0].z);
        GL21.glVertex3f(pts[1].x, pts[1].y, pts[1].z);
        GL21.glVertex3f(pts[2].x, pts[2].y, pts[2].z);
        GL21.glEnd();

        GL21.glDisable(GL21.GL_BLEND);
    }
}

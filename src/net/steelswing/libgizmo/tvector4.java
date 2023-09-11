/*
 * Ну вы же понимаете, что код здесь только мой?
 * Well, you do understand that the code here is only mine?
 */

package net.steelswing.libgizmo;

/**
 * File: tvector3.java
 * Created on 12 сент. 2023 г., 01:48:34
 *
 * @author LWJGL2
 */
public class tvector4 {

    public float x, y, z, w;

    public tvector4(float x, float y, float z, float w) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }

    public tvector4(float xyzw) {
        this(xyzw, xyzw, xyzw, xyzw);
    }

    public tvector4() {
        this(0);
    }

    public tvector4(tvector4 original) {
        this(original.x, original.y, original.z, original.w);
    }

    public tvector4 add(tvector4 other) {
        return tvector3(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    public tvector4 sub(tvector4 other) {
        return tvector3(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    public tvector4 mul(tvector4 other) {
        return tvector3(x * other.x, y * other.y, z * other.z, w * other.w);
    }

    public tvector4 div(tvector4 other) {
        return tvector3(x / other.x, y / other.y, z / other.z, w / other.w);
    }

    public tvector4 add(float otherx, float othery, float otherz, float otherw) {
        return tvector3(x + otherx, y + othery, z + otherz, w + otherw);
    }

    public tvector4 sub(float otherx, float othery, float otherz, float otherw) {
        return tvector3(x - otherx, y - othery, z - otherz, w - otherw);
    }

    public tvector4 mul(float otherx, float othery, float otherz, float otherw) {
        return tvector3(x * otherx, y * othery, z * otherz, w * otherw);
    }

    public tvector4 div(float otherx, float othery, float otherz, float otherw) {
        return tvector3(x / otherx, y / othery, z / otherz, w / otherw);
    }

    public tvector4 add(float otherxyzw) {
        return tvector3(x + otherxyzw, y + otherxyzw, z + otherxyzw, w + otherxyzw);
    }

    public tvector4 sub(float otherxyzw) {
        return tvector3(x - otherxyzw, y - otherxyzw, z - otherxyzw, w - otherxyzw);
    }

    public tvector4 mul(float otherxyzw) {
        return tvector3(x * otherxyzw, y * otherxyzw, z * otherxyzw, w * otherxyzw);
    }

    public tvector4 div(float otherxyzw) {
        return tvector3(x / otherxyzw, y / otherxyzw, z / otherxyzw, w / otherxyzw);
    }

    public float Dot(tvector3 v) {
        return (x * v.x) + (y * v.y) + (z * v.z);
    }

    public tvector4 tvector3(float x, float y, float z, float w) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
        return this;
    }


//    public   tvector3 tvector3(float x, float y, float z) {
//        return new tvector3(x, y, z);
//    }


    public static tvector4 add(tvector4 a, tvector4 b) {
        return new tvector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
    }

    public static tvector4 add(float a, tvector4 b) {
        return new tvector4(a + b.x, a + b.y, a + b.z, a + b.w);
    }

    public static tvector4 add(tvector4 a, float b) {
        return new tvector4(a.x + b, a.y + b, a.z + b, a.w + b);
    }

    public static tvector4 sub(tvector4 a, tvector4 b) {
        return new tvector4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
    }

    public static tvector4 sub(float a, tvector4 b) {
        return new tvector4(a - b.x, a - b.y, a - b.z, a - b.w);
    }

    public static tvector4 sub(tvector4 a, float b) {
        return new tvector4(a.x - b, a.y - b, a.z - b, a.w - b);
    }

    public static tvector4 mul(tvector4 a, tvector4 b) {
        return new tvector4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
    }

    public static tvector4 mul(float a, tvector4 b) {
        return new tvector4(a * b.x, a * b.y, a * b.z, a * b.w);
    }

    public static tvector4 mul(tvector4 a, float b) {
        return new tvector4(a.x * b, a.y * b, a.z * b, a.w * b);
    }

    public static tvector4 div(tvector4 a, tvector4 b) {
        return new tvector4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
    }

    public static tvector4 div(float a, tvector4 b) {
        return new tvector4(a / b.x, a / b.y, a / b.z, a / b.w);
    }

    public static tvector4 div(tvector4 a, float b) {
        return new tvector4(a.x / b, a.y / b, a.z / b, a.w / b);
    }

    public float DotNormal(tvector3 pvector) {
        return new tvector3(x, y, z).Dot(pvector) + w;
    }

    @Override
    public String toString() {
        return "tvector4{" + "x=" + x + ", y=" + y + ", z=" + z + ", w=" + w + '}';
    }
}

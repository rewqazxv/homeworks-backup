package com.etc.util;

public class Tuple3<A,B,C> {
    public A e1;
    public B e2;
    public C e3;
    public Tuple3(A e1, B e2, C e3) {
        this.e1 = e1;
        this.e2 = e2;
        this.e3 = e3;
    }

    public A getE1() {
        return e1;
    }

    public B getE2() {
        return e2;
    }

    public C getE3() {
        return e3;
    }
}
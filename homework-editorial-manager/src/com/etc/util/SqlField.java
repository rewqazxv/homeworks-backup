package com.etc.util;

import com.etc.pojo.Article;

import java.util.ArrayList;
import java.util.List;

public class SqlField {
    public static List<String> getJavaFields(Class c) {
        List<String> a = new ArrayList<>();
        for (var i : c.getDeclaredFields()) {
            a.add(i.getName());
        }
        return a;
    }

    public static String to_(String s) {
        StringBuilder bs = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (Character.isUpperCase(s.charAt(i)))
                bs.append('_').append(Character.toLowerCase(s.charAt(i)));
            else bs.append(s.charAt(i));
        }
        return bs.toString();
    }

    public static List<String> getSqlFields(Class c) {
        List<String> a = getJavaFields(c);
        for (int i = 0; i < a.size(); i++)
            a.set(i, to_(a.get(i)));
        return a;
    }

    public static String sqlUpdateSetString(Class c) {
        StringBuilder bs = new StringBuilder();
        for (var i : getJavaFields(c)) {
            bs.append(to_(i)).append("=#{").append(i).append("},");
        }
        return bs.substring(0, bs.length() - 1);
    }

    public static String sqlInsertValues(Class c) {
        StringBuilder bs = new StringBuilder("(");
        for (var i : getJavaFields(c)) {
            bs.append("#{").append(i).append("},");
        }
        bs.deleteCharAt(bs.length() - 1).append(")");
        return bs.toString();
    }

    public static String sqlInsertFields(Class c) {
        StringBuilder bs = new StringBuilder("(");
        for (var i : getSqlFields(c)) {
            bs.append(i).append(",");
        }
        bs.deleteCharAt(bs.length()-1).append(")");
        return bs.toString();
    }

    public static void main(String... args) {
        System.out.println(sqlUpdateSetString(Article.class));
        System.out.println(sqlInsertFields(Article.class));
        System.out.println(sqlInsertValues(Article.class));
    }
}

/**
 *
 */
package com.etc.exception;

/**
 * @author Administrator
 *  自定义的异常
 */
public class MyException extends Exception {

    private String message;

    public MyException() {
        super();
    }

    public MyException(String msg) {
        super();
        this.message = msg;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }


}

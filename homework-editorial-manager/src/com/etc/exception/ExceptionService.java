/**
 *
 */
package com.etc.exception;

import static org.hamcrest.CoreMatchers.instanceOf;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.io.Writer;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.web.servlet.HandlerExceptionResolver;
import org.springframework.web.servlet.ModelAndView;

/**
 * @author Administrator
 *
 */
public class ExceptionService implements HandlerExceptionResolver {

    /**
     * 异常的统一处理
     */
    public ModelAndView resolveException(HttpServletRequest request, HttpServletResponse response, Object arg2,
                                         Exception exception) {
        String msg = ""; // 打印的异常信息
        if (exception instanceof MyException) {
            msg = exception.getMessage();
        } else {
            // 如果是运行时异常，则取错误堆栈，从堆栈中获取异常信息
            Writer out = new StringWriter();
            PrintWriter s = new PrintWriter(out);
            exception.printStackTrace(s);
            msg = out.toString(); // 输出的异常信息

        }
        ModelAndView andView = new ModelAndView();
        andView.setViewName("exception");
        andView.addObject("msg", msg);
        return andView;
    }

}

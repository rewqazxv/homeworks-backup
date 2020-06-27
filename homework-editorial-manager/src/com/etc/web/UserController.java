package com.etc.web;

import com.etc.pojo.User;
import com.etc.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import javax.servlet.http.HttpSession;

@Controller  // 被spring托管
@RequestMapping(value = "/user") // 请求路径
public class UserController {
    // @Autowired  将service 注入 相当于  new UserService
    @Autowired
    private UserService userService;

    /**
     * 跳转到登录页面的方法
     * @return
     */
    @RequestMapping(value = "/toLoginController")
    public String toLoginController() {

        // 返回的字符串  视图
        return "login";
    }


    /**
     * 登录方法
     * 第一种获取值的方式 方法的参数列表  写要获取表单里的 name 属性的值
     *
     * Model 携带参数的接口
     * @return
     */
    @RequestMapping(value = "/loginController")
    public String loginController(@RequestParam("email") String email,
                                  @RequestParam("password") String password,
                                  Model model, HttpSession session) {
        User u = userService.checkEmailAndPwd(email, password);
        if (u == null) {
            // loginError 对应前台的 ${loginError}
            model.addAttribute("loginError", "用户名或密码错误");
            return "login";
        } else {
            // 将用户保存在整个会话中
            session.setAttribute("user", u);
            return "home";
        }
    }

    //---------------------------访问主体的四个页面------------------------------
    @RequestMapping(value = "/topController")
    public String topController() {
        return "top";
    }

    @RequestMapping(value = "/leftMenuController")
    public String leftMenuController() {
        return "leftMenu";
    }

    @RequestMapping(value = "/welcomeController")
    public String welcomeController() {
        return "welcome";
    }

    @RequestMapping(value = "/footController")
    public String footController() {
        return "foot";
    }

    //---------------------------用户信息------------------------------
    @RequestMapping(value = "/userInfoController")
    public String userInfoController() {
        return "userInfo";
    }

    @RequestMapping(value = "/logoutController")
    public String logout(HttpSession session) {
        session.removeAttribute("user");
        return "redirect:/";
    }
}

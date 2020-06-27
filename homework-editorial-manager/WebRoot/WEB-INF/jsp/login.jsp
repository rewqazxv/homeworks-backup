<!-- 添加jsp指令-->
<%@page language="java" pageEncoding="UTF-8" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="content-type" content="text/html;charset=utf-8">
    <title>投稿审稿系统</title>
    <link rel="stylesheet" href="${pageContext.request.contextPath}/styles/part.css"/>
    <script language="JavaScript">
        if (window != top) {
            top.location.href = location.href;
        }
    </script>
</head>
<body>
<div class="page-content">
    <form action="${pageContext.request.contextPath}/user/loginController" method="post">
        <fieldset>
            <legend>登录</legend>
            <table class="formtable" style="width:50%">
                <tr>
                    <td></td>
                    <td>
                        <font color='red'>${loginError}</font>
                    </td>
                </tr>
                <tr>
                    <td>账号名:</td>
                    <td>
                        <input id="email" name="email" type="text"/>
                    </td>
                </tr>
                <tr>
                    <td>密码:</td>
                    <td>
                        <input id="password" name="password" type="password"/>
                    </td>
                </tr>
                <tr>
                    <td colspan="2" class="command">
                        <input type="submit" value="登录" class="clickbutton"/>
                    </td>
                </tr>
            </table>
        </fieldset>
    </form>
</div>

</body>
</html>
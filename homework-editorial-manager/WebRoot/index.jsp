<!-- 添加jsp指令-->
<%@page language="java" pageEncoding="UTF-8" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>投稿审稿系统</title>
</head>
<body>
<!--${pageContext.request.contextPath} 获取项目的绝对路径-->
<a href="${pageContext.request.contextPath}/user/toLoginController">登录</a>
</body>
</html>
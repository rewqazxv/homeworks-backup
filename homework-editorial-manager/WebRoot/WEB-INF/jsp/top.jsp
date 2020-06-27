<%@page language="java" pageEncoding="UTF-8" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
    <link rel="stylesheet" href="${pageContext.request.contextPath}/styles/part.css"/>
</head>
<body>
<div class="page-header">
    <div class="header-banner">
        <img src="${pageContext.request.contextPath}/images/header.png" alt="logo"/>
    </div>
    <div class="header-title">
        投稿审稿管理系统
    </div>
    <div class="header-quicklink">
        欢迎您，<strong>${sessionScope.user.name}</strong>
        <a href="${pageContext.request.contextPath}/user/logoutController" target="_top">退出</a>
    </div>

</div>
</body>
</html>

<%@page language="java" pageEncoding="UTF-8" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
    <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/styles/menu.css"/>
</head>
<body>
<div class="page-sidebar">
    <div class="sidebar-menugroup">
        <c:if test="${sessionScope.user.isAdmin == 0}">
            <ul class="sidebar-menu">
                <li class="sidebar-menuitem">
                    <a href="${pageContext.request.contextPath}/user/userInfoController" target="main">个人信息</a>
                </li>
                <li class="sidebar-menuitem">
                    <a href="${pageContext.request.contextPath}/article/submitController"
                       target="main">新投稿</a>
                </li>
                <li class="sidebar-menuitem">
                    <a href="${pageContext.request.contextPath}/article/userAllArticlesController"
                       target="main">我的投稿</a>
                </li>
                <c:if test="${sessionScope.user.isReviewer == 1}">
                    <li class="sidebar-menuitem">
                        <a href="${pageContext.request.contextPath}/comment/todoController" target="main">待审稿</a>
                    </li>
                </c:if>
            </ul>
        </c:if>

        <c:if test="${sessionScope.user.isAdmin == 1}">
            <li class="sidebar-menuitem">
                <a href="${pageContext.request.contextPath}/article/allController" target="main">所有稿件</a>
            </li>
        </c:if>
    </div>
</div>
</body>
</html>

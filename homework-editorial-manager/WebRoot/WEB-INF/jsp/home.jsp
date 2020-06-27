<!-- 添加jsp指令-->
<%@page language="java" pageEncoding="UTF-8" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
    <title>投稿审稿管理系统</title>
</head>
<frameset rows="150,*,93" cols="*" framespacing="0" frameborder="no" border="0">
    <frame src="${pageContext.request.contextPath}/user/topController" name="topFrame" scrolling="No"
           noresize="noresize" id="topFrame" marginwidth="0" marginheight="0" frameborder="0"/>
    <frameset cols="260,*" id="frame">
        <frame src="${pageContext.request.contextPath}/user/leftMenuController" name="leftFrame" noresize="noresize"
               marginwidth="110px" marginheight="0" frameborder="0" scrolling="auto" target="main"/>
        <frame src="${pageContext.request.contextPath}/user/welcomeController" name="main" marginwidth="50px"
               marginheight="40px" frameborder="0" scrolling="auto" target="_self"/>
    </frameset>
    <frame src="${pageContext.request.contextPath}/user/footController" name="bottomFrame" scrolling="No"
           noresize="noresize" id="bottomFrame" marginwidth="0" marginheight="0"/>
</frameset>
<noframes></noframes>
</html>

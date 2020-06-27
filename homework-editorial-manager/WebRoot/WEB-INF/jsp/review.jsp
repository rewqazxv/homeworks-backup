<%@page language="java" pageEncoding="UTF-8" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
    <link rel="stylesheet" href="${pageContext.request.contextPath}/styles/content.css"/>
</head>
<body>

<div class="page-content">
    <c:if test="${submitSuccess}">
        <script>window.alert("提交成功！")</script>
    </c:if>
    稿件标题: ${article.title}<br/>
    作者: ${author.name}<br/>
    稿件正文:<br/>
    <textarea style="height:300px; background-color:#e5e5e5;" readonly>${article.content}</textarea><br/>
    <br/>
    <hr/>
    <hr/>
    <br/>
    <form action="${pageContext.request.contextPath}/comment/submitController/${review.id}" method="post">
        是否通过: (一旦通过不可撤回)
        <c:if test="${review.reviewPassed == 1}">
            <span style="color: green">☑</span>
        </c:if>
        <c:if test="${review.reviewPassed == 0}">
            <input name="mypassed" type="checkbox"/>
        </c:if>
        <br/>
        评议内容：<br/>
        <textarea name="content" style="height:200px;">${review.reviewComment}</textarea><br/>
        <input type="submit" value="更新评议" class="clickbutton"/>
    </form>
</div>
</body>
</html>
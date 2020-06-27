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
    <c:if test="${editArticle == null}">
        <form action="${pageContext.request.contextPath}/article/submitArticle" method="post">
            标题：<br/>
            <input name="title" type="text" style="width:300px;"/><br/>
            内容：<br/>
            <textarea name="content" style="height:300px;"></textarea><br/>
            <input type="submit" value="提交" class="clickbutton"/>
        </form>
    </c:if>

    <c:if test="${editArticle != null}">
        <form action="${pageContext.request.contextPath}/article/updateArticle/${editArticle.id}" method="post">
            标题：<br/>
            <input name="title" type="text" style="width:300px;" value="${editArticle.title}"/><br/>
            <c:if test="${sessionScope.user.isAdmin == 1}">
                作者：${idUserMap.get(editArticle.authorId).name}<br/>
            </c:if>
            内容：<br/>
            <textarea name="content" style="height:300px;">${editArticle.content}</textarea><br/>
            <c:if test="${sessionScope.user.id == editArticle.authorId}">
                <c:if test="${editArticle.passed == 0}">
                    <input type="submit" value="更新" class="clickbutton"/>
                </c:if>
                <c:if test="${editArticle.passed == 1}">
                    您已通过，不可修改。
                </c:if>
            </c:if>

            <c:if test="${sessionScope.user.id != editArticle.authorId}">
                您非作者。
            </c:if>
        </form>
        <br/>
        <hr/>
        <hr/>
        <br/>
        <c:forEach items="${reviews}" var="i">
            <c:if test="${sessionScope.user.isAdmin == 1}">
                审稿者: ${idUserMap.get(i.reviewerId).name}(${idUserMap.get(i.reviewerId).email})<br/>
            </c:if>
            意见:
            <c:if test="${i.reviewPassed == 1}">
                <span style="color: green">✓</span> <br/>
                <textarea style="height:100px;background-color:#b0e9c0;" readonly>${i.reviewComment}</textarea>
            </c:if>

            <c:if test="${i.reviewPassed == 0}">
                <c:if test="${i.reviewDate.after(editArticle.updateDate)}">
                    <span style="color: red">✗</span> <br/>
                    <textarea style="height:100px;background-color:#e9a9a9;" readonly>${i.reviewComment}</textarea>
                </c:if>
                <c:if test="${i.reviewDate.before(editArticle.updateDate)}">
                    <span style="color: grey">-</span> <br/>
                    <textarea style="height:100px;background-color:#e5e5e5;" readonly>${i.reviewComment}</textarea>
                </c:if>
            </c:if>
            <br/>
        </c:forEach>
    </c:if>
</div>
</body>
</html>
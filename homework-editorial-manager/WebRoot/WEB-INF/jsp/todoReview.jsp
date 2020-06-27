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
    <table class="listtable">
        <tr>
            <td>稿件标题</td>
            <td>作者</td>
            <td>评议状态</td>
            <td>通过状态</td>
        </tr>
        <c:forEach items="${tuple3List}" var="i">
            <tr>
                <td>
                    <a href="${pageContext.request.contextPath}/comment/reviewController/${i.e1.id}">
                            ${i.e2.title}
                    </a>
                </td>
                <td>${i.e3.name}</td>
                <td>
                    <c:if test="${i.e1.reviewDate.before(i.e2.updateDate)}"><span style="color:red;">需要审核</span></c:if>
                    <c:if test="${i.e1.reviewDate.after(i.e2.updateDate)}">已审核</c:if>
                </td>
                <td>
                    <c:if test="${i.e1.reviewPassed == 1}"><span style="color:green;">已通过</span></c:if>
                    <c:if test="${i.e1.reviewPassed == 0}">未通过</c:if>
                </td>
            </tr>
        </c:forEach>
    </table>
</div>

</body>
</html>
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
            <td>标题</td>
            <c:if test="${idUserMap != null}">
                <td>作者</td>
            </c:if>
            <td>更新时间</td>
            <td>评议状态</td>
        </tr>
        <c:forEach items="${articles}" var="i">
            <tr>
                <td>
                    <a href="${pageContext.request.contextPath}/article/articleDetailController/${i.id}">
                            ${i.title}
                    </a>
                </td>
                <c:if test="${idUserMap != null}">
                    <td>${idUserMap.get(i.authorId).name}</td>
                </c:if>
                <td>${i.updateDate}</td>
                <td>
                    <c:if test="${i.passed == 1}"><span style="color:green;">已通过</span></c:if>
                    <c:if test="${i.passed == 0}"><span style="color:gray;">尚未通过</span></c:if>
                </td>
            </tr>
        </c:forEach>
    </table>
</div>

</body>
</html>
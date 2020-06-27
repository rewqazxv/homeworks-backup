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
    姓名: ${sessionScope.user.name}<br />
    邮箱: ${sessionScope.user.email}<br />
    单位: ${sessionScope.user.unit}<br />
    评议权限: <c:if test="${sessionScope.user.isReviewer == 1}">有</c:if><c:if test="${sessionScope.user.isReviewer == 0}">无</c:if><br />
</div>

</body>
</html>
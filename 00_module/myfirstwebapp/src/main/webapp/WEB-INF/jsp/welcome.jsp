<html>
    <head>
        <title>Welcome page</title>
        <link href="webjars/bootstrap/5.1.3/css/bootstrap.min.css" rel="stylesheet">
    </head>
    <body>
        <%@ include file="common/navigation.jspf" %>
        <div class="container">
            <h1>WelCome ${name}</h1>
            <a href="list-todos">Manage</a> your todos
        </div>
        <script src="webjars/bootstrap/5.1.3/js/bootstrap.min.js"></script>
        <script src="webjars/jquery/3.6.0/jquery.min.js"></script>
    </body>
</html>
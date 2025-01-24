# 노트

## 0. Building First Web Application
* Browser, HTML, CSS, Request, Response, Form, Session, Authentication
* Spring MVC (Dispatcher Servlet, View Resolvers, Model, View, Controller, Validations, ...)
* Spring Boot (Starters, Auto Configuration)
* Frameworks/Tools (JSP, JSTL, JPA, Bootstrap, Spring Security, MySQL, H2)
* To-do Management Web app 구축하기 

## 1. Spring initializr 
* Group ID, Artifact ID 지정
* Dependencies
    * Spring Web > Spring MVC를 이용해서, RESTful을 비롯한 웹 애플리케이션 구축
        * 기본 임베디드 컨테이너는 Apache Tomcat을 사용한다.
    * Spring Boot DevTools > 빠를 애플리케이션 재시작, 라이브 리로드 등 개발 편의성 제공

## 2. Spring boot 프로젝트 간단히 살펴보기
* 프로젝트 구조 확인하기
* `application.properties`
    * 애플리케이션 세부정보 설정
~~~
// 포트 8081로 설정
server.port=8081
~~~
* `pom.xml`
    * dependency
    * Java version 설정 등

## 3. Spring MVC Controller
* RequestMapping > URL mapping 
* ResponseBody > return 한 그대로를 브라우저에 리턴하는 것을 의미한다.
* `SayHelloController`
~~~
@Controller
public class SayHelloController {
    @RequestMapping("say-hello")
    @ResponseBody
    public String sayHello() {
        return "Hello! What are you learning today?";
    }
}
~~~
![say-hello_page](./img/say-hello_page.png)

## 4-1. HTML 응답 제공 위해 Spring MVC 컨트롤러 개선하기
* HTML을 return 하는 메서드
* `SayHelloController`
~~~
@RequestMapping("say-hello-html")
@ResponseBody
public String sayHelloHtml() {
    StringBuffer sb = new StringBuffer();
    sb.append("<html>");
    sb.append("<head>");
    sb.append("<title> My first HTML Page - Changed</title>");
    sb.append("</head>");
    sb.append("<body>");
    sb.append("My first html page with body Changed");
    sb.append("</body>");
    sb.append("</html>");
    return sb.toString();
}
~~~

## 4-2. Code or debugging
* 강의를 들으면서 문제가 발생할 시, 깃허브 링크 참고!
* [in28minutes-github-link](https://github.com/in28minutes/master-spring-and-spring-boot/blob/main/11-web-application/99-step-by-step-changes.md)

## 5. SpringBoot Controller, @ResponseBody, 뷰를 이용하여 JSP로 리디렉션하기
1. `pom.xml`에 dependency 추가
    * tomcat-embed-jasper (jsp파일 해석 및 처리)
~~~
<dependency>
    <groupId>org.apache.tomcat.embed</groupId>
    <artifactId>tomcat-embed-jasper</artifactId>
</dependency>
~~~

2. JSP 파일 생성
    * `src/main/webapp/WEB-INF/jsp` 해당 경로에 jsp 파일 (view)을 넣어서 보관해야 함
    * HTML로 작성

3. `application.properties` 수정
    * 접두사 = prefix
        * /src/main/webapp 까지의 경로는 spring이 이미 알고있음. 
    * 접미사 = suffix
        * 파일의 확장자 (.jsp)
~~~
spring.mvc.view.prefix=/WEB-INF/jsp/
spring.mvc.view.suffix=.jsp
~~~

4. Mapping 추가
    * @ResponseBody 가 있으면 return 되는 String 값을 출력하니 주의!
~~~
@Controller
public class SayHelloController {
    @RequestMapping("say-hello-jsp")
    public String sayHelloJsp() {
    return "sayHello";
    }
}
~~~

## 6. 예제 - LoginController와 login 뷰 만들기 
1. login 패키지에 LoginController 클래스를 만듦
* `src/main/java/com/hyun/springboot/myfirstwebapp/login/LoginController.java`
~~~
@Controller
public class LoginController {

    @RequestMapping("login")
    public String login() {
        return "login";
    }
}
~~~

2. jsp 파일 생성
* `src/main/webapp/WEB-INF/jsp/login.jsp`
* HTML로 컨텐츠 작성

![login_page](./img/login_page.png)

## 7. 웹의 작동 방식 - 요청과 응답
* String으로 반환된 것은 텍스트로만 표시한다.
* html을 리턴하면 브라우저가 그걸 이해하고 표시한다.
* F12 > Network > sayHello.jsp 
    * Request URL > http://localhost:8080/say-hello-jsp
    * Request Method > GET
    * Status Code > 200
* URL을 건드리면, 브라우저가 요청을 전송 
    * HttpRequest
* 우리 서버 or 애플리케이션은 요청을 받으면 그 요청을 처리하게 된다.
    * Spring Boot 웹 애플리케이션이 요청을 받은 후 처리
* 서버 or 애플리케이션이 응답을 return

## 8. RequestParam으로 쿼리 파라미터 잡기, 모델 소개
* 특정한 URL에 정보를 전달하는 가장 쉬운 방법은 쿼리 파라미터를 사용하는 방법이다.
* URL에 쿼리 파라미터를 추가하면 요청은 먼저 해당되는 Controller로 간다
* 이를 @RequestParam 어노테이션을 사용해서 컨트롤러 메서드에서 수학할 수 있다
    * 여기서는 LoginController  
* 이를 Model Mapping을 통해서 jsp파일 (뷰)로 전달할 수 있다.


1. URL에 쿼리 파라미터 추가
    * ?name= 추가
~~~
http://localhost:8080/login?name=hyun
~~~

2. Controller에 RequestParam 어노테이션 추가
~~~
@RequestMapping("login")
public String loginPage(@RequestParam String name) {
    System.out.println("Request param is : " + name);
    return "login";
}
~~~
3. 결과

![RequestParam](./img/Request_param.png)

4. login.jsp에서 param을 사용하려면?
* 여기서 중요한 개념인 모델(Model)이 등장한다.
    * 컨트롤러에서 jsp로 전달하려할 때, 파라미터를 모델에 넣어서 전달할 수 있다.
* Spring MVC가 제공하는 옵션 중에는 ModelMap이 존재.
* @RequestParam 과 전달하려는 변수 타입과 변수이름을 설정
* ModelMap을 활용, put으로 name을 전달한다.
* jsp 파일에 변수를 저장한다.
~~~
public class LoginController {

    // http://localhost:8080/login?name=hyun
    @RequestMapping("login")
    public String loginPage(@RequestParam String name, ModelMap model) {
        model.put("name", name);
        System.out.println("Request param is : " + name);
        return "login";
    }
}
~~~
* `login.jsp`
~~~
<html>
    <head>
        <title>Login page</title>
    </head>
    <body>
        Hello this is Login Page ${name}!
    </body>
</html>
~~~
* 결과

![RequestParam2](./img/Request_param2.png)

## Spring Boot를 사용할 때 로깅의 중요성
* 프로덕션 중에 문제를 디버깅할 때, 로그를 확인하면서 시간을 보내게 된다.
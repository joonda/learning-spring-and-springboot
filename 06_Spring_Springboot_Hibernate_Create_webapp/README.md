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

## 9. Spring Boot를 사용할 때 로깅의 중요성
* Spring Boot 에서는 `application.properties` 를 통해 로깅을 설정할 수 있다.
* debug, info, trace, error, warn 등의 레벨이 있다.
#### 클래스를 선택해서 로깅 하기
~~~
#application.properties

logging.level.org.springframework=info
logging.level.com.in28minutes.springboot.myfirstwebapp=debug
~~~
* `logging.level.` 이후에 패키지를 입력, 특정 패키지의 로깅 범위를 지정할 수 있다.

#### slf4j를 사용해서 로깅 하기
* `System.out.println()`을 활용해서 터미널에 로깅을 해왔지만 Logger를 사용해서 로깅할 수 있다.
~~~
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

@Controller
public class LoginController {

    private Logger logger = LoggerFactory.getLogger(getClass());
    @RequestMapping("login")
    public String loginPage(@RequestParam String name, ModelMap model) {
        model.put("name", name);
        System.out.println("Request param is : " + name);
        logger.debug("Request Param is {}",name);
        return "login";
    }
}
~~~
* `private Logger logger = LoggerFactory.getLogger(getClass());`
    * Logger 선언
* debug()
    * Logger의 메서드
    * info, warn으로 바꿔도 가능하다 (해당 레벨에 맞춰서 로깅이 된다.)
    * {}을 기준으로 변수를 넣어주면 된다 (printf를 생각하면 편할 듯)
* 사진을 보면, println처럼 나오는 것이 아닌, logging이 나오는 것을 알 수 있다.
![logging](./img/logging.png)
* spring에서는 로깅을 권장하는 편이다.

## 10. 디스패치 서블릿, 모델1, 모델2, 프론트 컨트롤러 알아보기
#### 웹 애플리케이션 개발의 역사
![Model1_Arch](./img/Model1_Arch.png)
* 뷰에 모든 코드를 작성 (jsp) / 컨트롤러가 존재하지 않음
    * View 로직 : 페이지를 표시하는 방법 (HTML, CSS)
    * Flow 로직 : 페이지를 표시하는 방법에 (페이지 순서 등) 관한 로직 
    * 데이터베이스 쿼리 : 데이터베이스와 상호작용을 위한 쿼리 (SQL 쿼리)
        * 이를 화면에 표시해야 했다.
* 단점
    * 너무 복잡하다 
    * 주제별로 구분되지도 않았음
        * 뷰, 흐름, 데이터베이스 로직 등 모든 것이 jsp 안에 존재
    * 유지 보수의 어려움

![Model2_Arch](./img/Model2_Arch.png)
* 주제별로 분명하게 구분됨
    * Model : View를 생성하는 데 사용하는 데이터 
    * View : 정보를 사용자에게 보여주는 역할 
    * Controller : 전체 흐름 제어
* 이점
    * 유지하기 비교적 쉬워짐
* 고민
    * 공통 기능을 모든 컨트롤러에 걸쳐 구현하는 방법이 고민이었다.
        * 인증 로직을 예시로 들면, 인증 로직은 모든 서블릿에 걸쳐 비슷하다
            * 모든 서블릿에 걸쳐 어떻게 공통적으로 구현할 수 있을까 ?

![Model2_Arch2](./img/Model2_Arch2.png)
* 컨셉: 모든 브라우저의 요청은 중앙에 있는 FrontController 하나로 간다
* 프론트 컨트롤러는 컨트롤러, 뷰, 서블릿으로 가는 흐름을 제어했다.
    * 공통 기능은 프론트 컨트롤러에 구현

![Dispatcher_Servlet](./img/Dispatcher_Servlet.png)
* 디스패처 서블릿 : Spring MVC에서 구현한 Front Controller
* HTTP 요청 처리 과정
    1. 모든 요청은 디스패처 서블릿이 받는다
    2. 모델, 뷰, 컨트롤러를 사용하여 URL이 무엇인지 식별 (localhost:8080/login)
    3. 요청을 처리할 수 있는 컨트롤러 메서드 실행 (LoginController())
    4. 렌더링할 적절한 뷰를 식별, `login`인 경우에는 `login.jsp`를 표시
        * view resolver를 활용
            * `spring.mvc.view.prefix=/WEB-INF/jsp/`
            * `spring.mvc.view.suffix=.jsp`
    5. 응답을 리턴

## 11. 로그인 양식 만들기
* form 태그를 활용해서 양식을 만든다.
~~~
<form>
    Name : <input type="text" name="name">
    Password : <input type="password" name="password">
    <input type="submit">
</form>~
~~~
* 아이디와 패스워드를 입력 시, URL에 정보가 전송되고 있음을 확인할 수 있다.

![loginPage](./img/loginPage.png)

* `GET`을 사용하면 모든 정보가 URL의 일부로서 전송된다
    * 안전하지 못한 방법 대신 `POST`를 쓴다
~~~
// form method에 post를 추가
<form method="post">
    Name : <input type="text" name="name">
    Password : <input type="password" name="password">
    <input type="submit">
</form>
~~~

* 헤더를 보면, 메서드가 POST로 바뀐것을 확인할 수 있고 페이로드에 Form Data의 일부로서 전송되는 것을 확인할 수 있다.

![loginPage2](./img/loginPage2.png)

* 웹사이트에 전송하려는 모든 보안 정보는 항상 post를 사용하는 것이 좋다.
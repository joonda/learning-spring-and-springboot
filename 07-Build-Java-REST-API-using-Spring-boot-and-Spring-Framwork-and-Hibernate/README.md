# 노트

## 0. Spring Boot로 REST API 생성하기 - 개요
#### Spring Boot로 REST API 만들기 - 목표
* 왜 스프링부트일까?
    * Spring boot 없이도 REST API를 생성할 수 있다.
    * 왜 스프링 부트를 사용할까 ?
* 어떻게 좋은 REST API를 만들 수 있을까 ?
    * REST API에 포함되어야 하는 리소스를 어떻게 알 수 있을까? (/users, /users/{id}/posts)
    * 작업을 식별하는 것은 어떻게 할 수 있을까? (GET, POST, PUT, DELETE, ...)
    * 요청과 응답 구조는 어떻게 정의할 수 있을까?
    * 적절한 응답 상태 (200, 404, 500, ...)
    * REST API의 우수사례
        * 늘 소비자 관점에서 바라봐야 한다
        * Validation, Internationalization - i18n, Exception Handling, HATEOAS, Versioning, Documentation, Content Negotiation, ...

#### Spring Boot로 REST API 만들기 - 접근법
* 1: 3개의 간단한 Hello World REST API를 만들기
    * Spring Boot를 이해
    * Spring Boot를 통한 REST API 빌드의 기본을 알아보기
        * @RestController, @RequestMapping, @PathVariable, JSON conversion
* 2: 소셜 미디어 애플리케이션 용 REST API 빌드 해보기
    * 좋은 REST API 설계
        * 리소스에 알맞는 URI (/users, /users/{id}, /users/{id}/posts)
        * 알맞은 요청 메서드 선택 (GET, POST, PUT, DELETE)
    * REST API 고급 기능을 사용해보기
        * Internationalization, HATEOAS, Versioning, Documentation, Content Negotiation, ... 
* 3: REST API를 데이터베이스에 연결하는 법
    * 가장 널리 쓰이는 방식은 JPA, Hibernate이다.
    * H2, MySQL Database 사용
        * H2는 인메모리 데이터베이스이다.

## 1. Spring Boot로 REST API 프로젝트 초기화하기
#### Spring initializr
* [Spring initializr](https://start.spring.io/)
* Dependencies
    * Spring Web
    * Spring Data JPA
    * H2 Database
    * Spring Boot DevTools

## 2. Spring Boot로 Hello World REST API 생성하기
* `HelloWorldController`
~~~java
@RestController
public class HelloWorldController {

    @RequestMapping(method = RequestMethod.GET, path = "/hello-world")
    public String helloWorld() {
        return "Hello World";
    }
}
~~~
* GET 요청으로 불러오며, path는 원하는 url 엔드포인트로 지정 (여기서는 `/hello-world`로 지정.)
* String인 Hello World를 리턴함
![hello-world-rest-api](./img/hello-world-rest-api.png)

`HelloWorldController`
~~~java
@RestController
public class HelloWorldController {

    @GetMapping(path = "/hello-world")
    public String helloWorld() {
        return "Hello World";
    }
}
~~~
* 조금 더 직관적으로 보여주기 위해, RequestMapping 보다는 GetMapping을 사용.

## 3. Hello World REST API를 업그레이드하여 Bean 반환하기

`HelloWorldController`
~~~java
@RestController
public class HelloWorldController {
    // ... 생략
    @GetMapping(path = "/hello-world-bean")
    public HelloWorldBean helloWorldBean() {
        return new HelloWorldBean("Hello World");
    }
}
~~~

`HelloWorldBean`
~~~java
public class HelloWorldBean {
    private String message;

    public HelloWorldBean(String message) {
        this.message = message;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    @Override
    public String toString() {
        return "HelloWorldBean{" +
                "message='" + message + '\'' +
                '}';
    }
}
~~~
![hello-world-rest-api-json](./img/hello-world-rest-api-json.png)

* Controller에서 return이 단순 String이면, 문자열 그대로 반환
* return이 자바 객체이면 JSON으로 반환
    * 단, 자바 객체에 `생성자`, `Getter()`, `Setter()`, `toString()` 등의 메서드가 존재해야함

## 4. 백엔드에는 어떤 일이 벌어지고 있을까? Spring Boot 스타터와 자동 설정

`application.properties`
~~~
logging.level.org.springframwork=debug
~~~

* 백그라운드 단에서 동작하는 원리를 알아보기 위해 Debug logging 활성화
    * 로그는 주기적으로 바뀐다는 것을 유의

* 1: 요청은 어떻게 동작할까?
    * DispatcherServlet - Front Controller Pattern (Spring MVC 에서 모든 요청은 디스패처 서블릿이 처리한다)
        * Mapping servlets: dispatcherServlet urls=[/]
            * 디스패처 서블릿이 url을 확인하고, 알맞은 컨트롤러 메서드에 매핑
        * 디스패처 서블릿은 자동 설정에 의해 설정됨

* 2: 어떻게 `HelloWorldBean` 객체가 JSON으로 반환될까?
    * `@ResponseBody` + JacksonHttpMessageConverters
        * `@ResponseBody` : 응답을 HTTP 응답 본문으로 직접 전송
            * `@RestController` 내부에서 사용하고 있음.
        * JacksonHttpMessageConverters 자동 설정 (JSON 처리)

* 3: 에러 매핑은 어디서 설정할까?
    * 잘못된 url(엔드포인트)를 입력하면, Whitelabel 오류가 뜬다 (404)
    * 오류페이지 역시 자동 설정의 결과

* 4: 어떻게 모든 jar들을 사용할 수 있냐 (Spring, Spring MVC, Jackson, Tomcat)?
    * Starter Project 때문이다
    * Starter Projects - Spring Boot Starter Web (spring-webmvc, spring-web, spring-boot-starter-tomcat, spring-boot-starter-json)

## 5. 패스 변수로 Hello World REST API 업그레이드 하기
#### Path Parameters
* /users/{id}/todos/{id} => /users/2/todos/200
    * 이러한 변수들을 패스 매개변수라고 칭한다.

~~~java
@RestController
public class HelloWorldController {
    // ... 생략
    @GetMapping(path = "/hello-world/path-variable/{name}")
    public HelloWorldBean helloWorldPathVariable(@PathVariable String name) {
        return new HelloWorldBean(String.format("Hello World, %s", name));
    }
}
~~~

* path안에 `{}`를 넣어 변수를 지정, 메서드 파라미터에 `@PathVariable`을 지정하고 변수의 타입과 이름을 넣어준다.

## 6. SNS 애플리케이션용 REST API 설계하기
#### SNS 애애플리케이션용 REST API 설계
* Key Resources
    * Users
    * Posts
* Key Details
    * User : id, name, birthDate
    * Post : id, description

#### REST API 설계를 위한 요청 메서드
* GET - 특정 리소스에서 상세 정보를 검색
* POST - 새 리소스를 만들고자할 때 사용 
* PUT - 기존에 있는 리소스를 업데이트 할 때 사용
* PATCH - 기존 리소스의 일부만 업데이트 할 때 사용
* DELETE - 특정 리소스를 삭제

#### SNS 애플리케이션 용용 Resources & Methods
* Users REST API
    * 모든 사용자 검색
        * GET 요청 /users
    * 사용자 생성
        * POST 요청 /users
    * 특정 사용자 검색
        * GET 요청 /users/{id} -> /users/1
    * 특정 사용자 삭제
        * DELETE 요청 /users/{id} -> /users/1
    * 포스팅 REST API
        * 사용자가 포스팅한 글
            * GET 요청 /users/{id}/posts
        * 사용자가 포스팅을 만들 때
            * POST 요청 /users/{id}/posts
        * 특정 포스팅을 찾을 때 
            * GET 요청 /users/{id}/posts/{id}

## 7. 사용자 Bean과 UserDaoService 생성하기
* 사용자 정보를 담은 사용자 Bean을 만들어 보자
`User`
~~~java
public class User {
    private Integer id;
    private String name;
    private LocalDate birthDate;

    // 생성자, Getter(), Setter(), toString() 메서드
}
~~~
* 사용자 Bean을 중심으로 하는 REST API 만들기 
    * 사용자 상세정보를 저장, 검색, 특정 사용자 삭제 등 데이터베이스를 관리하고, 데이터베이스에 저장된 데이터를 가지고 작업을 하려면 DAO 객체를 만들어야한다.

`UserDaoService`
~~~java
@Component
public class UserDaoService {
    // JPA/Hibernate > Database

    private static List<User> users = new ArrayList<>();

    static {
        users.add(new User(1, "Adam", LocalDate.now().minusYears(30)));
        users.add(new User(2, "Eve", LocalDate.now().minusYears(25)));
        users.add(new User(3, "Jim", LocalDate.now().minusYears(20)));
    }

    public List<User> findAll() {
        return users;
    }

    public User findOne(int id) {
        Predicate<? super User> predicate =
                user -> user.getId().equals(id);
        return users.stream().filter(predicate).findFirst().get();
    }
}
~~~

## 8. User Resource에서 GET 메서드 구현하기
~~~java
@RestController
public class UserResource {

    private UserDaoService userDaoService;

    // @Autowired 생략략
    public UserResource(UserDaoService userDaoService) {
        this.userDaoService = userDaoService;
    }

    @GetMapping("/users")
    public List<User> retrieveAllUsers() {
        return userDaoService.findAll();
    }

    @GetMapping("/users/{id}")
    public User retrieveUsers(@PathVariable int id) {
        return userDaoService.findOne(id);
    }

}
~~~
* 생성자 주입 `UserResource` (생성자가 하나면 `@Autowired` 생략 가능)
* /users 엔드포인트 접근시, 모든 사용자
* /users/{id} 엔드포인트 접근시 (e.g. /users/1), 아이디에 해당하는 사용자

## 9. User Resource에서 POST 메서드 구현하기
`UserResource`
~~~java
@RestController
public class UserResource {

    // ... 생략
    @PostMapping("/users")
    public void createUser(@RequestBody User user) {
        userDaoService.save(user);
    }
}
~~~

`UserDaoService`
~~~java
@Component
public class UserDaoService {
    // JPA/Hibernate > Database

    private static List<User> users = new ArrayList<>();

    static {
        users.add(new User(1, "Adam", LocalDate.now().minusYears(30)));
        users.add(new User(2, "Eve", LocalDate.now().minusYears(25)));
        users.add(new User(3, "Jim", LocalDate.now().minusYears(20)));
    }
    // ... 생략
    public User save(User user) {
        user.setId(++usersCount);
        users.add(user);
        return user;
    }
}
~~~
* [Talend API Tester](https://chromewebstore.google.com/detail/talend-api-tester-free-ed/aejoelaoggembcahagimdiliamlcdmfm)
* 아쉽게도 GET과 달리, 브라우저에서는 POST 요청을 바로 보낼 순 없다.
    * POST로 요청을 보내려면, REST API 클라이언트가 필요하다.
![rest-api-client-talend-api](./img/rest-api-client-talend-api.png)

* Method 지정, URL, BODY를 입력해서 요청을 보냈다
    * ID는 동적으로 받기 때문에 넣지 않음.
![post-method-success](./img/post-method-success.png)
![post-method-success-check](./img/post-method-success-check.png)

## 10. POST 메소드를 개선해 올바른 HTTP 상태 코드와 Location
#### REST API의 다양한 응답 형태
* 200 (OK) : 성공
* 201 (Created) : POSt 요청으로 새 리소스를 생성했을 때 
* 204 (No Content) : 성공, 응답으로 반환할 본문 없음
    * PUT, DELETE후 정상적으로 데이터베이스 반영이 되었음을 알리는 용도
* 400 (Bad Request) : 정보 전달 시, 해당 정보가 검증을 통과 못한 경우 (검증 에러 등)
* 401 (Unauthorized) : 요청에 올바른 정보를 제공하지 않을 때 (인증 실패)
* 404 (Not Found) : 요청 리소스가 존재하지 않는 경우
* 500 (Server Exception) : 서버에서 예외가 발생한 상황

#### User POST API에 201 요청 실습
`UserResource`
~~~java
@RestController
public class UserResource {

    // ... 생략
    @PostMapping("/users")
    public ResponseEntity<User> createUser(@RequestBody User user) {
        userDaoService.save(user);

        return ResponseEntity.created(null).build();
    }
}
~~~
* 기존의 void 반환 타입에서 ResponseEntity를 반환하고, Object는 User를 반환한다.

#### Location
`UserResource`
~~~java
@RestController
public class UserResource {

    @PostMapping("/users")
    public ResponseEntity<User> createUser(@RequestBody User user) {
        User savedUser = userDaoService.save(user);

        URI location = ServletUriComponentsBuilder.fromCurrentRequest()
                .path("/{id}")
                .buildAndExpand(savedUser.getId())
                .toUri();
        
        return ResponseEntity.created(location).build();
    }
}
~~~
* 기존의 null이었던 `create()` 메서드를 location으로 채웠다.
    * `ServletUriComponentsBuilder.fromCurrentRequest()` : HTTP 요청 정보를 기반으로 URI 빌더 생성
    * `path("/{id}")` : 생성된 리소스의 URI 경로, id 추가
* 이를 통해, POST API 요청으로 생성된 `USer`의 id가 포함된 url이 리턴된다
    * http://localhost:8080/users/4
    * 해당 로케이션 url을 GET 메서드로 요청, 생성된 유저 확인 가능

![post-method-201-response](./img/post-method-201-response.png)

## 11. 예외 처리 구현하기 - 404 Resource Not found
* 만약 존재하지 않는 사용자를 조회할 시 500 에러가 발생한다.
    * localhost:8080/users/101
    * 이를 404 (Not Found)로 변경이 필요하다.

#### `findOne()` 수정
~~~java
@Component
public class UserDaoService {
    public User findOne(int id) {
        Predicate<? super User> predicate =
                user -> user.getId().equals(id);
        return users.stream().filter(predicate).findFirst().orElse(null);
    }
}
~~~
* return 문에 null을 넣어서 존재하지 않는 페이지로 접근하면 아무것도 뜨지 않는다.

#### `UserResource::retrieveUsers`
~~~java
@RestController
public class UserResource {
    // ... 생략
    @GetMapping("/users/{id}")
    public User retrieveUsers(@PathVariable int id) {
        User user = userDaoService.findOne(id);

        if (user == null)
            throw new UserNotFoundException("id:" + id);
        return user;
    }
    // ... 생략
}
~~~
* `userDaoService::findOne()` 메서드의 결과가 null로 리턴 시, 예외 처리 

#### `UserNotFoundException` 
~~~java
@ResponseStatus(code = HttpStatus.NOT_FOUND)
public class UserNotFoundException extends RuntimeException {

    public UserNotFoundException(String s) {
        super(s);
    }
}
~~~
* 커스텀 예외 클래스를 만든다.
* `@ResponseStatus`로 HTTP 코드 지정 가능
* 생성자를 통해, 외부에서 주입 

## 12. 모든 리소스를 대상으로 예외 처리 구현하기
#### `ErrorDetails`
~~~java
public class ErrorDetails {
    private LocalDateTime timestamp;
    private String message;
    private String details;

    // 생성자, Getter(), Setter()
}
~~~

#### `ResponseEntityExceptionHandler`
~~~
{
"timestamp": "2024-06-30T10:39:01.153+00:00",
"status": 404,
"error": "Not Found",
"message": "id:4",
"path": "/users/4"
}
~~~
* 예외 발생 시, 기본적인 Handler 양식

#### `ResponseEntityExceptionHandler`를 상속하여 커스텀 예외 핸들러 만들기
~~~java
@ControllerAdvice
public class CustomizedResponseEntityExceptionHandler extends ResponseEntityExceptionHandler {
    @ExceptionHandler(Exception.class)
    public final ResponseEntity<ErrorDetails> handleAllException(Exception ex, WebRequest request) {
        ErrorDetails errorDetails = new ErrorDetails(request.getDescription(false),
                ex.getMessage(), LocalDateTime.now());
        return new ResponseEntity<ErrorDetails>(errorDetails, HttpStatus.INTERNAL_SERVER_ERROR);
    }
}
~~~

#### 특정 예외 클래스에 대한 예외처리
~~~java
@ControllerAdvice
public class CustomizedResponseEntityExceptionHandler extends ResponseEntityExceptionHandler {
    @ExceptionHandler(UserNotFoundException.class)
    public final ResponseEntity<ErrorDetails> handleUserNotFoundException(Exception ex, WebRequest request) {
        ErrorDetails errorDetails = new ErrorDetails(request.getDescription(false),
                ex.getMessage(), LocalDateTime.now());
        return new ResponseEntity<ErrorDetails>(errorDetails, HttpStatus.NOT_FOUND);
    }
}
~~~
* `@ControllerAdvice` : 애플리케이션 전체에서 발생하는 예외 처리 클래스에게 부여
    * 일반적으로 `ResponseEntityExceptionHandler` 클래스 확장하여 사용, 필수적이진 않다 

## 13. DELETE 메소드로 사용자 리소스 삭제하기
#### User 삭제 메서드 추가
~~~java
@Component
public class UserDaoService {
    // ... 생략
    public void deleteById(int id){
        Predicate<? super User> predicate =
                user -> user.getId().equals(id);
        users.removeIf(predicate);
    }
}
~~~

#### `User 삭제 API 추가`
~~~java
@RestController
public class UserResource {
    // ... 생략
    @DeleteMapping("/users/{id}")
    public void deleteUser(@PathVariable int id) {
        userDaoService.deleteById(id);
    }
}
~~~

## 14. REST API에서 유효성 검증하기
* POST로 신규 User 생성 시, 필드가 빈 값이거나, 출생일이 미래시점으로 되어있는 경우에도 생성이 가능하다 유효성 검증 기능을 추가할 것

* `pom.xml`에 의존성 추가
~~~xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-validation</artifactId>
</dependency>
~~~

* `UserResource` 클래스내의 메서드에 `@Valid` 어노테이션 추가
~~~java
@RestController
public class UserResource {
    // ... 생략
    @PostMapping("/users")
    public ResponseEntity<User> createUser(@Valid @RequestBody User user) {
        User savedUser = userDaoService.save(user);

        URI location = ServletUriComponentsBuilder.fromCurrentRequest()
                .path("/{id}")
                .buildAndExpand(savedUser.getId())
                .toUri();

        return ResponseEntity.created(location).build();
    }
    // ... 생략
}
~~~

* `User` 클래스에 조건을 추가
~~~java
public class User {
    private Integer id;

    @Size(min=2, message = "이름은 2글자 이상이어야 합니다.")
    private String name;

    @Past(message = "생일은 과거 시점이어야 합니다.")
    private LocalDate birthDate;

    // 생성자, Getter(), Setter() 메서드
}
~~~
* `@Size` : 최소 입력 문자 지정
* `@Past` : 무조건 과거 시점이어야 한다 (생일이 미래시 일 순 없기 때문)
* 에러시, 메시지를 띄울 수 있다.

* `CustomizedResponseEntityExceptionHandler`
~~~java
@ControllerAdvice
public class CustomizedResponseEntityExceptionHandler extends ResponseEntityExceptionHandler {
    // ... 생략
    @Override
    protected ResponseEntity<Object> handleMethodArgumentNotValid(MethodArgumentNotValidException ex, HttpHeaders headers, HttpStatusCode status, WebRequest request) {
        ErrorDetails errorDetails = new ErrorDetails(request.getDescription(false),
                "Total Errors Count: " + ex.getErrorCount() + ", Default Error: " + ex.getFieldError().getDefaultMessage(),
                LocalDateTime.now());

        return new ResponseEntity<>(errorDetails, HttpStatus.BAD_REQUEST);
    }
}
~~~
* 400 에러에 대해 `handleMethodArgumentNotValid` 메서드 재정의
* `ex.getMessage()`가 너무 많은 내용을 담고 있어 커스텀 메시지 리턴
    * `ex.getErrorCount()` : 발생 오류 갯수
    * `ex.getDefaultMessage()` : 첫번째 오류 메시지

## 15. 고급 REST API 기능의 개요
* REST API에 대한 문서
* 콘텐츠 협상 (Content Negotiation)
* 국제화 (Internationalization) - i18n
* 여러 버전의 REST API 생성하는 방법
* HATEOAS
* Static Filtering
* Dynamic Filtering
* Monitoring
* ...
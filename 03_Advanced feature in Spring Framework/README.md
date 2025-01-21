# 노트

## 1. Spring Bean Initialization // package d1
* Spring Bean의 Default initialization : 즉시 초기화
    * Spring Context를 실행하면, 바로 초기화가 발생한다
* 지연 초기화를 하고 싶다면, 적용하고 싶은 Class에 @Lazy annotation 사용!
    * Lazy 적용된 이후에는 클래스의 Bean을 사용할 때 초기화 된다.
    * 자주 사용되지는 않는다.
* Component, Bean 대부분 사용 가능
* Configuration Class에서도 사용 가능.

## 2. Lazy Initialization vs. Eager Initialization // package d1
* Initialization time
    * Lazy : 애플리케이션에서 처음 사용될 때 초기화
    * Eager : 애플리케이션이 시작되거나, Spring Context가 실행될 때 초기화 (바로)
* Default
    * Lazy : @Lazy or @Lazy(value=true)
    * Eager : @Lazy(value=false) or @Lazy를 없앤다.
* 초기화에서 에러가 발생한다면?
    * Lazy : 오류는 런타임 예외 에러
    * Eager : 애플리케이션이 작동하지 않는다.
* 빈도
    * Lazy : 드물게 사용
    * Eager : 대부분 사용 
* 메모리 사용
    * Lazy : Eager에 비해 메모리 사용량이 적을 수 있다 (initialization하기 전까지는 실행을 안함)
    * Eager : 모든 것이 시작할 때 로드 됨 (시작 시 모든 것이 초기화)

## 3. Bean Scope - Prototype or Singleton // package e1
* Prototype
    * Spring Context에서 새로운 Bean을 매번 가져오는 것 (호출할 때 마다)
    * 즉, Bean을 요청할 때마다 Bean 인스턴스가 새로 생성됨.
* Singleton (Default)
    * 이전에 생성했던 Bean을 재사용
* Another Scope
    * Request - 각 HTTP 요청 당 객체 인스턴스 하나가 생성
    * Session - user HTTP 세션 당 객체 인스턴스 하나가 생성
    * Application - 웹 애플리케이션 전체에 객체 인스턴스 하나가 생성
    * Websocket - 웹소켓 인스턴스 당 객체 인스턴스 하나가 생성
* Java Singleton (GOF) vs. Spring Singleton
    * Spring IoC : 컨테이너 하나에는 객체 인스턴스가 하나
    * Java Singleton : JVM 하나 당 객체 인스턴스가 하나
    * 대부분 JVM에 Spring Container 여러개를 실행하지는 않기 때문에 Java Singleton == Spring Singleton이다
        * 예외 존재할 수 있음!

## 4. Compare Prototype and Singleton Bean Scope // package e1
* Instance
    * Prototype : Spring IoC 컨테이너 하나 당 여러개가 될 수 있음
    * Singleton : Spring IoC 컨테이너 하나 당 하나.
* Beans
    * Prototype : Bean을 참조할 때마다 새로운 Bean 인스턴스 생김
    * Singleton : 같은 Bean을 지속적으로 사용.
* Default
    * Prototype : Not Default
    * Singleton : Default
* Code
    * Prototype : @Scope(value = ConfigurationBeanFactory.SCOPE_PROTOTYPE)
    * Singleton : @Scope(value = ConfigurationBeanFactory.SCOPE_SINGLETON) OR Default
* 빈도
    * Prototype : 거의 안씀
    * Singleton : 거의 모든 Spring Bean에서 사용
* 시나리오
    * Prototype : 사용자 정보가 유지되는 Bean
    * Singleton : 사용자 정보가 없거나 or 일반적

## 5. PostConstruct, PreDestroy // package f1
* PostConstruct
    * 초기화를 수행하기 위해 의존성 주입이 완료된 후 실행해야하는 메서드에서 사용
    * 해당 메서드는 클래스를 사용하기 전에 호출되어야 한다.
    * 즉, 다른 Bean이 적용된 해당 Bean을 사용할 수 있게 되기 전에 해당 메서드가 호출된다.
* PreDestroy
    * 보유하고 있던 리소스를 해제하는 데 일반적으로 사용
    * Bean의 생명주기가 끝나고 직전에 PreDestroy를 사용 (예를들면 db연결 해제 등..)

## 6. Jakarta EE vs. J2EE vs. Java EE
* 순서는 J2EE -> Java EE -> Jakarta EE
* 초기 Java 버전에서 엔터프라이즈 기능 대부분은 JDK에 Java 언어로 직접 구축
* 시간이 지나면서 기능들이 분리됨
    * J2EE - Java 2 Platform 엔터프라이즈 에디션 (1.2, 1.3, 1.4)
    * Java EE - Java Platform 엔터프라이즈 에디션 (Rebranding J2EE) (5 to 8)
    * Jakarta EE - Java EE의 소유자였던 Oracle에서 Java EE의 권리를 이클립스에 넘겼음 (이후)
        * 이클립스에서는 여론조사를 통해 Java EE를 Jakarta EE로 바꿈
* Jakarta EE
    * Important Specifications
        * Jakarta Server Page (JSP)
            * 웹 애플리케이션의 뷰를 만드는 것에 사용
        * Jakarta Standard Tag Library (JSTL)
            * 웹 페이지에 동적 정보를 나타내는 데 사용할 수 있는 태그 라이브러리
        * Jakarta Enterprise Beans (EJB)
        * Jakarta RESTful Web Services (JAX-RS)
            * Jakarta RESTful Web Services 규격
        * Jakarta Bean Validation
        * Jakarta Contexts and Dependency Injection (CDI)
        * Jakarta Persistence API (JPA)
    * Supported by Spring 6 and Spring Boot 3

## 7 Jakarta Contexts & Dependency Injection (CDI) // package g1
* Spring Framework V1 was released in 2004
* CDI는 규격이고 인터페이스이다.
    * Spring에서 CDI를 구현한다.
* Important Inject API Annotations
    * Inject (~Autowired in Spring)
    * Named (~Component in Spring)
    * Qualifier
    * Scope
    * Singleton

## 8 XML 설정 // package h1
* resources 디렉토리에 contextConfiguration.xml 생성
* Bean 정의를 할 수 있다.
* 최근에는 XML 설정은 거의 필요하지 않는다.
* 아직 오래된 프로젝트에서는 사용하고 있을 가능성이 높기 때문이다.

## 9 Annotation vs. XML Configuration
* Easy
    * Annotations : 쉬움
    * XML Configuration : 번거롭다 (xml 파일에 Bean 등을 일일이 설정해줘야함.)
* 짧고 간결함
    * Annotations : Yes
    * XML Configuration : No
* Clean POJOs
    * Annotations : No (Annotation은 결국엔 Spring Framework에서 import를 해야함)
    * XML Configuration : Yes (XML 파일에 모든 것을 다 정의함. import가 따로 필요가 없다.)
* 관리성
    * Annotations : 매우 쉬움
    * XML Configuration : 어려움 (XML 파일에 우겨넣기 때문에 코드 량이 상당하다.)
* 사용빈도
    * Annotations : 대부분 프로젝트는 Anotation 사용
    * XML Configuration : 드물다 (이전)
* Debugging difficulty
    * Annotations : Hard
    * XML Configuration : Medium

## 10 Spring Stereotype Annotations
* @Component
    * 기본적인 Annotation
    * 모든 클래스에 적용이 가능.
    * @Component를 대체할 수 있는 것
        * @Service : Annotation한 Class에 비즈니스 논리가 있음을 나타낸다.
        * @Controller : 컨트롤러 클래스인 경우 (e.g. web controller)
            * 웹 애플리케이션, REST API에서 컨트롤러를 정의하는 데 사용
        * @Repository : Bean이 DB와 통신하는 경우, 데이터를 저장 or 검색 or 조작하는 경우
* 무엇을 써야하는가?
    * 최대한 구체적인 Annotation 사용 권장
    * 프레임워크에 자신이 의도했던 바를 더 자세하게 나타낼 수 있다.
    * 특정 클래스에 대한 역할 정보를 제공
    * AOP (관점 지향 프로그래밍)를 사용하여 어노테이션을 감지하고 부가적인 동작을 추가할 수 있다.

## 11 Important Spring Annotations
* @Configuration
    * 클래스가 @Bean 메서드를 하나 이상 선언함을 나타낸다.
    * Spring Container에서 처리하여 Bean 정의를 생성

* @ComponentScan
    * Spring Framework에서는 모든 컴포넌트가 정의된 위치를 알아야한다.
    * 해당 어노테이션을 사용하면, 컴포넌트를 스캔할 패키지를 지정할 수 있다.
    * 지정하지 않으면, 해당 어노테이션을 선언한 클래스의 패키지에서 찾는다.
        * 해당 패키지의 하위 패키지까지 찾는다.

* @Component
    * 어노테이션한 클래스가 컴포넌트임을 나타낸다.

* @Service
    * 어노테이션한 클래스가 비즈니스 로직이 있음을 나타내는 Component의 한 종류

* @Controller
    * 어노테이션한 클래스가 컨트롤러임을 나타내는 Component의 한 종류
    * 일반적으로 웹 애플리케이션과 REST API에서 컨트롤러 정의에 사용

* @Repository
    * 어노테이션한 클래스가 데이터베이스에서 데이터를 검색하거나 조작하는 데 사용된다.

* @Primary
    * 여러 Bean이 단일 값 의존성에 자동 연결될 후보일 때 Bean에 우선순위를 매긴다.

* @Qualifier
    * 자동 연결 시 후보 Bean의 한정자로 필드나 매개변수에서 활용

* @Lazy
    * Spring Bean은 일반적으로 즉시 초기화 (컨텍스트가 실행되는대로 초기화 진행)
    * 지연 초기화를 위해 해당 어노테이션 사용

* @Scope
    * prototype scope -> Bean 호출 때마다 새로운 객체를 지속해서 만들어낸다.
    * default scope는 singleton 이다.

* @PostConstruct
    * 의존성 주입이 수행된 이후 초기화를 위해 실행될 메서드 
    * 모든 의존성을 Bean에 주입한 후, 초기화하려는 경우 모든 의존성이 준비되는 대로 DB에서 몇 가지 값을 가져오려는 경우

* @PreDestroy
    * 컨테이너에서 인스턴스를 삭제하는 과정을 거치고 있음을 알려주는 콜백 알림을 수신하는 메서드
    * 보통 특정한 Bean에서 보유하고 있는 리소스를 해제하는 데 사용됨.
    * 컨테이너나 Spring IoC 컨텍스트에서 Bean이 삭제되기 전에 @PreDestroy 어노테이션이 붙은 메서드를 호출한다.

* @Named
    * CDI (Jakarta Contexts & Dependency Injection), Component와 유사하다

* @Inject
    * Autowired와 유사하다.

## 12 Important Spring Concepts
* Dependency Injection
    * Spring Framework에서는 Bean을 확인해야 하고, 의존성을 확인해야한다.
    * Spring Framework가 객체를 만들고 작성한다. (IoC)
    * Constructor Injection
    * Setter Injection
    * Field Injection
* IoC Container
    * Spring Bean과 그들의 라이프사이클을 책임지는 Context
* Bean Factory
    * Basic Spring IoC Container
* Application Context
    * 가장 많이 사용되는 Context(Compare Bean Factory)
* Spring Bean
    * Spring에서 관리하는 객체
* Auto-Wiring
    * Spring Bean의 의존성을 자동으로 연결해주는 과정

## 13 Spring Big Picture
* Spring Core -> IoC Container, Dependency Injection, Auto Wiring
    * Building web applications
    * Creating REST API
    * Implementing authentication and authorization
    * Database Connect
    * Integrating with other systems
    * Writing great unit tests (단위 테스트) 
* Spring Big Picture
    * Spring Framework
    * Spring Modules
    * Spring Projects
* Framework and Modules
    * 기본 코어 기능 : IoC Container, Dependency Injection, Auto Wiring
    * 웹 : Spring MVC etc (Web applications, REST API)
    * 반응형 웹 : Spring WebFlux etc
    * 데이터 접근 : JDBC, JPA etc
    * 다른 Application과 통합 : JMS etc 
    * Testing : Mock Objects, Spring MVC Test etc
* 왜 스프링은 모듈로 나눠져 있을까 ?
    * 각 모듈은 유연성을 가질 수 있도록 설계
* Spring Project
    * 애플리케이션 아키텍셔는 점점 더 발전
    * Web Application > REST API > MicroServices > Cloud
* Spring은 가장 자주쓰이는 Framework
    * Spring Security
        * Web Application, REST API에 보안을 추가할 때 사용
        * 마이크로서비스에 인증, 권한 부여를 추가하려는 경우
    * Spring Data
        * 여러 데이터베이스와 통합할 시, Spring Data를 사용
        * 이전에는 관계형 데이터베이스를 많이 사용, 요즘에는 NoSQL 데이터베이스 사용
    * Spring Integration
        * 애플리케이션에서 통합 관련 문제를 해결할 때 사용
    * Spring Boot
        * 마이크로서비스를 빌드하는 프레임워크
    * Spring Cloud
        * Spring Native 애플리케이션을 빌드할 때는 Spring 프로젝트인 Spring Cloud 사용
* Spring 생태계는 왜 이렇게 인기가 많을까?
    * Spring은 느슨한 결합이 가능하다.
        * Spring은 Bean 생성, Bean과 의존성 연결을 관리
        * 유지보수가 가능한 애플리케이션을 매우 쉽게 만들 수 있다.
        * 단위 테스트 작성 수월하다.
    * 보일어플레이트 코드를 줄여준다.
        * 즉 비즈니스 로직에 집중할 수 있다.
        * 예외 처리를 작성할 필요가 없다.
    * 아키텍서 유연성
        * Spring은 여러 개의 모듈로 나뉘어 있음.
        * 사용할 모듈과 프로젝트를 고르고, 모두 사용할 필요 전혀 없다
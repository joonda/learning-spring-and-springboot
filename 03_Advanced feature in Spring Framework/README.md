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

## 7 Jakarta Contexts & Dependency Injection (CDI)
* Spring Framework V1 was released in 2004
* CDI는 규격이고 인터페이스이다.
    * Spring에서 CDI를 구현한다.
* Important Inject API Annotations
    * Inject (~Autowired in Spring)
    * Named (~Component in Spring)
    * Qualifier
    * Scope
    * Singleton

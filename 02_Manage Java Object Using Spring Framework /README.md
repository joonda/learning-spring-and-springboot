# 노트

## 1. Spring 자바 객체
* @ComponentScan을 통해, 원하는 package의 주소를 입력.
* @Component 끼리 자동 와이어링을 해준다
* 선언한 package 주소를 디버깅 해보면 오류를 찾는 게 더 쉬워질 것이다.

## 2. Spring Component
* @Primary -> Bean 후보가 여러개인 경우, 우선권을 부여할 수 있다. (기본 값 지정)
* @Qualifier -> 기본 값 지정이 되어있지만, 우선권을 주고 싶을 때 부여할 수 있다 (한정자 지정)

## 3. Primary, Qualifier
* 어떤 Spring annotation을 사용해야할까?
* @Primary인 경우, 여러 후보가 자격이 존재할 시, 해당 Bean에게 우선권을 주는 것.
    * 1개일 때는 해당되는 Bean을 주고, 복수 개수인 상황에서는 제일 적당한 것을 지정해서 주는 관점
* @Qualifier인 경우, 특정 Bean이 자동 와이어링이 되어야 한다. 
    * 특정 Bean만 사용되는 경우
* Primary보다 Qualifier가 더 높은 우선순위를 갖고 있다는 것을 항상 생각!

## 4. Dependency Injection
* 생성자 주입
    * 클래스의 생성자에 @Autowired를 붙여서 주입
~~~
Dependency1 dependency1;
Dependency2 dependency2;

@Autowired // 생성자가 1개만 있을 때, 생략 가능
public YourBusinessClass(Dependency1 dependency1, Dependency2 dependency2) {

    System.out.println("Constructor Injection - YourBusinessClass");
    this.dependency1 = dependency1;
    this.dependency2 = dependency2;
}
~~~

* 수정자 주입
    * 클래스의 세터에 @Autowired를 붙여서 주입
~~~
Dependency1 dependency1;
Dependency2 dependency2;

@Autowired
public void setDependency1(Dependency1 dependency1) {
    System.out.println("Setter Injection - setDependency1");
    this.dependency1 = dependency1;
}

@Autowired
public void setDependency2(Dependency2 dependency2) {
    System.out.println("Setter Injection - setDependency2");
    this.dependency2 = dependency2;
}
~~~

* 필드 주입
    * 클래스의 필드에 직접 @Autowired를 붙여서 주입
    * 생성자나 수정자가 없다.
~~~
// 클래스의 필드에 바로 주입
@Autowired
Dependency1 dependency1;
@Autowired
Dependency2 dependency2;
~~~

## 5. 용어 이해
* @Component
    * 클래스에 추가하는 경우, 클래스의 인스턴스는 Spring 프레임워크가 관리한다.

* Dependency
    * GameRunner는 Game이 필요하다
    * 이전에 만들었던 Mario, SuperContra, PacMan 등은 GameRunner의 의존성이다.

* @ComponentScan
    * 스프링이 컴포넌트 클래스를 어떻게 찾는가?
        * 위치를 지정 -> ("com.hyun.~~~")
        * 패키지 이름이 없이 추가한다면, 현재 패키지에서 찾는다.

* Dependency Injection
    * Application을 실행하면, ComponentScan을 수행 (모둔 구성 요소 찾는다.)
    * Component의 의존성을 무엇인지 식별, 와이어링 수행 (Bean과 의존성을 식별, 와이어링 진행)  
        * Spring Beans
            * 스프링 프레임워크가 관리하는 모든 객체
        * IOC -> Inversion of Control
            * Bean의 생명 주기와 의존성을 관리하는 Spring 프레임워크의 컴포넌트
            * Types
                * ApplicationContext
                * BeanFactory

* Autowiring
    * Spring Bean에 대한 의존성의 와이어링 프로세스
    * Spring이 특정 Bean을 만나면, Bean이 필요한 의존성이 무엇인지 식별하려 한다.

## 6. Component vs Bean
* Where
    * Component -> 모든 자바 클래스
    * Bean -> 특정 메소드에 적용, (Spring Configuration class)
* Autowiring
    * Component -> 필드, 생성자, 수정자 주입 가능
    * Bean -> 메소드 호출, 메소드 파라미터
* Creates Bean
    * Component -> Spring Framework
    * Bean -> write bean creation code
* Recommend
    * Component -> 일반적으로 권장
    * Bean -> 비즈니스 로직 작성, 제 3자 라이브러리 Bean을 인스턴스 (e.g. Spring Security)

## 7. Java Spring Application에 의존성이 있는 이유
* 
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
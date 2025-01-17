# 노트

## 1단계 - Java Spring Framework가 필요한 이유 

### 애플케이션 아키텍처의 발전 
Wep App -> REST API -> Full Stack -> Microservices

### 애플리케이션 구축을 위한 프레임워크
* Spring MVC
* Hibernate
* Spring Security
* Spring Data
* Spring Cloud

### Spring 프레임 워크
* 의존성 주입, 자동 연결 지원
* 훨씬 적은 코드로 더 많은 일을 할 수 있도록 한다.

### Spring 프레임 워크와 밀접하게 연관된 용어
* 강한 결합 (Tight Coupling)
* 느슨한 결합 (Loose Coupling)
* 의존성 주입 (Dependency Injection)
* IOC 컨테이너 (IOC Container)
* 애플리케이션 컨텍스트 (Application Context)
* Spring Bean
* 자동 연결 (Auto Wiring)
* 컴포넌트 스캔 (Component Scan)

## 프로젝트 구축 및 Maven, Spring framework 프로젝트 생성하기

## 4단계
* 마리오 게임 구현

## 5단계
* 강한 결합
    * 무언가를 변경하는 데 얼마나 많은 작업이 관련되어 있는지의 척도
    * 마리오 게임 대신 수퍼콘트라 게임으로 실행하려면 특정 클래스에서 많은 변화를 주어야 한다.
    * 예를 들어, 차의 엔진은 차와 강하게 결합되어있지만, 바퀴는 차에 느슨하게 연결되어있다.
        * 타이어 바람이 빠진다면, 쉽게 바꿀수 있는 것!
        * 유사한 예로 노트북 vs. 데스크탑
    * 가능한 한 코드를 적게 변경하면서 기능을 변경할 수 있어야 한다 -> 느슨한 결합!
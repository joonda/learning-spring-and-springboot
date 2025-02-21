# 노트

## 1. React 풀 스택 애플리케이션을 위해 Todo REST API 프로젝트 설정하기
* REST API
    * Hello World REST API:
        * Hello World:
            * `@GetMaaping(path="/hello-world")`
        * Hello World Bean:
            * `@GetMaaping(path="/hello-world-bean")`
        * Hello World Path Variable:
            * `@GetMaaping(path="/hello-world/path-variable/{name}")`
    * Todo REST API
        * Retrieve Todos
            * `@GetMapping("/users/{username}/todos")`
        * Retrieve Todo 
            * `@GetMapping("/users/{username}/todos/{id}")`
        * Delete Todo
            * `@DeleteMapping("/users/{username}/todos/{id}")`
        * Update Todo
            * `@PutMapping("/users/{username}/todos/{id}")`
        * Create Todo
            * `@PostMapping("/users/{username}/todos")`

## 2. React Hello World 컴포넌트에서 Spring Boot Hello World REST API 호출하기

#### 리액트 애플리케이션에서 REST API 호출하기
`WelcomeComponent.jsx`
```javascript
import { useParams, Link } from "react-router-dom"

export default function WelcomeComponent() {
    const param = useParams()
    return (
        <div className="Welcome">
            <h1>Welcome to {param.username}</h1>
            <div>
                Manage Your todos - <Link to='/todos'>Go here</Link>
            </div>
            <div>
                <button className="btn btn-success m-5"
                    onClick={() => {
                        return console.log("called")
                    }}
                >
                    Call Hello World REST API
                </button>
            </div>
        </div>
    )
}
```
* REST API를 호출하기 위해 `button`을 추가하고, onClick 리스너를 붙인다.

#### Axios
* 리액트를 사용할 때, REST API를 호출하기 위해 가장 널리 사용하는 프레임워크

```terminal
npm install axios
```

`WelcomeComponent.jsx`
```javascript
import { useParams, Link } from "react-router-dom"
import axios from "axios";

export default function WelcomeComponent() {

    function callHelloWorldRestApi() {
        console.log('called')
        axios.get('http://localhost:8080/hello-world-bean')
    }
    // ... 생략
    return (
        // ... 생략
    )
}
```

* `axios`를 사용해서 API 호출을 할 때는 세 가지를 할 수 있다.
    * `then`, `finally`, `catch`


`WelcomeComponent.jsx`
```javascript
import { useParams, Link } from "react-router-dom"
import axios from "axios";

export default function WelcomeComponent() {

    function callHelloWorldRestApi() {
        console.log('called')
        axios.get('http://localhost:8080/hello-world-bean')
            .then((response) => successfulResponse(response))
            .catch((error) => errorResponse(error))
            .finally(() => console.log('cleanup'))
    }

    function successfulResponse(response) {
        console.log(response)
    }

    function errorResponse(error) {
        console.log(error)
    }
    // ... 생략
    return (
        // ... 생략
    )
}
```
* `callHelloWorldRestApi` 정의
    * axios를 활용하여 get 메서드로 api를 불러온다.
* 만약에 성공한다면, `then`으로 `successfulResponse()` 메서드를 불러온다.
* 에러가 발생한다면, `catch`로 `errorResponse()` 메서드를 불러온다
* 마지막에는 콘솔에서 'cleanup' 이라는 문구를 프린트하게 한다.
* 결과적으로는 CORS 정책 때문에 불러오는 것이 차단되었다고 뜬다.
![rest-api-error-cors-policy](./img/rest-api-error-cors-policy.png)

## 3. Spring Boot REST API에 대해 CORS 요청 활성화하기
#### CORS (Cross Origin Requests)
* 이전 단계에서 REST API를 호출하려 했으나, CORS 에러가 발생했다
* 이는 다른 도메인에서 오는 요청의 허용 여부를 결정하는 보안 기능
    * e.g. `localhost:3000`에서한 요청은 오직 `localhost:3000` 에서 와야 하는 것!

`RestfulWebServicesApplication.java`
```java
// ... 생략
@SpringBootApplication
public class RestfulWebServicesApplication {

	public static void main(String[] args) {
		SpringApplication.run(RestfulWebServicesApplication.class, args);
	}

	@Bean
	public WebMvcConfigurer corsConfigurer() {
		return new WebMvcConfigurer() {
			public void addCorsMappings(CorsRegistry registry) {
				registry.addMapping("/**")
						.allowedMethods("*")
						.allowedOrigins("http://localhost:3000");
			}
		};
	}
}
```
* `WebMvcConfigurer`: CORS 에러를 해결하기 위해서 `Spring MVC`에서 설정을 커스터마이징할 수 있는 인터페이스인 `WebMvcConfigurer`를 선언하여 configurer 객체를 생성
* `addCorsMappings`: CORS 관련 설정을 추가하는 메서드 (정의)
* `registry.addMapping("/**")`: 모든 URL 경로에 대해 CORS 설정을 적용
* allowedMethods("*"): 모든 HTTP 메서드 (`GET`,`POST`,`PUT`,`DELETE`)에 대해 CORS 요청을 허용 
* allowedOrigins("url"): 특정 경로에서 오는 요청만 허용 ("http://localhost:3000")
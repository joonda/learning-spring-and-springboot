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
        axios.get('http://localhost:8080/hello-world')
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

## 4. React에서 Spring Boot Hello World Bean과 패스 변수 REST API 호출하기

#### REST API 데이터 표출하기
* `useState()`를 활용한다
* 여기서는 hello-world, hello-world-bean 두 개의 경로의 JSON 데이터를 받아서 표출한다

```javascript
import { useParams, Link } from "react-router-dom"
import axios from "axios";
import { useState } from "react";

export default function WelcomeComponent() {

    const [message, setMessage] = useState(null)
    const [message2, setMessage2] = useState(null)

    function callHelloWorldRestApi() {
        console.log('called')
        axios.get('http://localhost:8080/hello-world')
            .then((response) => successfulResponse(response))
            .catch((error) => errorResponse(error))
            .finally(() => console.log('cleanup'))
    }

    function callHelloWorldBeanRestApi() {
        console.log('called')
        axios.get('http://localhost:8080/hello-world-bean')
            .then((response) => setMessage2(response.data.message))
            .catch((error) => console.log(error))
            .finally(() => console.log('cleanup'))
    }

    function successfulResponse(response) {
        console.log(response)
        setMessage(response.data)
    }

    function errorResponse(error) {
        console.log(error)
    }

    const param = useParams()
    return (
        <div className="Welcome">
            <h1>Welcome to {param.username}</h1>
            <div>
                Manage Your todos - <Link to='/todos'>Go here</Link>
            </div>
            <div>
                <button className="btn btn-success m-5"
                    onClick={callHelloWorldRestApi}
                >
                    Call Hello World REST API
                </button>
            </div>
            <div className="text-info">
                {message}
            </div>
            <div>
                <button className="btn btn-success m-5"
                    onClick={callHelloWorldBeanRestApi}
                >
                    Call Hello World Bean REST API
                </button>
            </div>

            <div className="text-info">
                {message2}
            </div>

        </div>
    )
}
```
* `useState(null)`로 데이터 초기값을 null로 초기화 한다
    * `setMessage` 함수로 데이터 response를 받아와서 대체할 예정
* `hello-world` 경로에 있는 response를 활용, `response.data`로 메시지를 표출한다
* `hello-world-bean` 경로에 있는 response를 활용, `response.data.message`로 메시지를 표출한다
![called-rest-api](./img/called-rest-api.png)

## 5. Spring Boot REST API 호출 코드를 별도의 모듈에 리팩터링하기
#### REST API 호출의 세부적인 내용을 별도로 관리
* `src/components/todo/api` 폴더 생성
* `api` 폴더에 `HelloWorldApiService.js` 파일 생성
* REST API 호출 코드를 옮긴다.

`HelloWorldApiService.js`
```javascript
import axios from "axios";

// export function retrieveHelloWorldBean () {
//     return axios.get('http://localhost:8080/hello-world-bean')
// }

export const retrieveHelloWorldBean = () => axios.get('http://localhost:8080/hello-world-bean')
```
* `retrieveHelloWorldBean` 함수를 export
* 위의 함수를 사용해도되고, 화살표 함수를 사용한 것도 가능하다.


`WelcomeComponent.jsx`
```javascript
export default function WelcomeComponent () {
    // ... 생략
    function callHelloWorldBeanRestApi() {
        console.log('called')
        retrieveHelloWorldBean()
            .then((response) => setMessage2(response.data.message))
            .catch((error) => console.log(error))
            .finally(() => console.log('cleanup'))
    }
    // ... 생략
}
```
* 이전에 export한 `retrieveHelloWorldBean` 함수를 `axios.get()` 대신 사용


## 6. Spring Boot REST API에서 Axios를 사용하는 최적의 방식
#### REST API 호출 추가하기
`HelloWorldApiService.js`
```javascript
import axios from "axios";

const apiClient = axios.create(
    {
        baseURL: 'http://localhost:8080'
    }
)
// export function retrieveHelloWorldBean () {
//     return apiClient.get('http://localhost:8080/hello-world-bean')
// }

export const retrieveHelloWorldBean = () => apiClient.get('/hello-world-bean')

export const retrieveHelloWorldPathVariable = (username) => apiClient.get(`/hello-world/path-variable/${username}`)
```
* `axios.create()`를 활용하여 baseURL을 지정한다.
* path-variable 경로의 REST API 호출 추가
* username을 변수로 받아서 처리.

`WelcomeComponent.jsx`
```javascript
export default function WelcomeComponent () {
    // ... 생략
    function callHelloWorldPathVariable() {
        console.log('called')
        // 변수 추가
        retrieveHelloWorldPathVariable('Hyun')
            .then((response) => setMessage3(response.data.message))
            .catch((error) => console.log(error))
            .finally(() => console.log('cleanup'))
    }
    // ... 생략
}
```
* 일단 하드코딩으로 `retrieveHelloWorldPathVariable()`에 'Hyun' 이라는 변수를 추가해서 API 호출

## 7. Retrieve Todos Spring Boot REST API GET 메서드 

#### Todo 목록을 가져오기 위해 GET 메서드 만들기
`TodoResource`
```java
package com.in28minutes.rest.webservices.restfulwebservices.todo;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class TodoResource {

    private TodoService todoService;

    // 생성자 주입
    public TodoResource(TodoService todoService) {
        this.todoService = todoService;
    }

    @GetMapping("/users/{username}/todos")
    public List<Todo> retrieveTodos(@PathVariable String username) {
        return todoService.findByUsername(username);
    }
}
```
* `Todo`에는 `id`, `username`, `description`, `targetDate`, `done`의 Getter, Setter, toString, 생성자가 있는 Class
* `TodoService`에는 `findByUsername`, `addTodo`, `deleteById`, `findById`, `updateTodo` 메서드가 존재
* `username`에 맞는 `Todo` 목록을 가져오기 위해 `TodoResource` 클래스를 만든다.
    * `http://localhost:8080/users/{username}/todos` 경로로 이동시, JSON 형태로 데이터가 반환되는 걸 확인할 수 있다.
![todos-json-data](./img/todos-json-data.png)

## 8. React 앱에서 Spring Boot REST API로부터 Todo 표시하기
#### REST API를 활용하여 Todo 목록 표시

`TodoApiService.js`
```javascript
import axios from "axios";

const apiClient = axios.create(
    {
        baseURL: 'http://localhost:8080'
    }
)

export const retrieveAllTodosForUsername
    = (username) => apiClient.get(`/users/${username}/todos`)
```
* REST API 경로를 설정, username을 변수로 받기 때문에 해당 변수를 URL에 넣어준다.

`ListTodosComponent.jsx`
```javascript
import { useEffect, useState } from "react";
import { retrieveAllTodosForUsername } from "./api/TodoApiService";

export default function ListTodosComponent() {

    const [todos, setTodos] = useState([])

    useEffect (() => refreshTodos(), {})

    function refreshTodos() {
        
        retrieveAllTodosForUsername('Hyun')
        .then(response => {
            setTodos(response.data)
        })
        .catch(error => console.log(error))
    }

    return (
        // ... 생략
    )
}
```
* `useState()` 활용하여 todos를 가져온다.
* `retrieveAllTodosForUsername('Hyun')` 파라미터에 username을 하드코딩하여 데이터를 가져온다.
* `setTodos(response.data)`로 데이터들을 받아온다

## 9. Todo를 받고 삭제하는 Spring Boot REST API 메서드 만들기 
#### 특정한 Todo에 관한 세부정보를 받은 후, 해당 Todo를 삭제하는 법
* 특정한 Todo에 접근하여 삭제를 진행
`TodoResource.java`
```java
package com.in28minutes.rest.webservices.restfulwebservices.todo;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class TodoResource {

    private TodoService todoService;

    // 생성자 주입
    public TodoResource(TodoService todoService) {
        this.todoService = todoService;
    }

    // ... 생략
    @GetMapping("/users/{username}/todos/{id}")
    public Todo retrieveTodo(@PathVariable String username, @PathVariable int id) {
        return todoService.findById(id);
    }

    @DeleteMapping("/users/{username}/todos/{id}")
    public ResponseEntity<Void> deleteTodo(@PathVariable String username, @PathVariable int id) {
        todoService.deleteById(id);
        return ResponseEntity.noContent().build();
    }
}
```
* Talend API Tester로 확인이 가능하다
* 응답이 `204 No Content`로 나온다
* 하지만 현재 `TodoService`에서 정적 리스트로 가져오는 것이기 때문에 삭제해도 금방 돌아온다. (의미가 없다.)

## 10. React 프론트엔드에 삭제 기능 추가하기
#### 삭제 기능을 추가하기 위해 id를 파라미터로 받아오는 함수 정의
`TodoApiService.js`
```javascript
import axios from "axios";

const apiClient = axios.create(
    {
        baseURL: 'http://localhost:8080'
    }
)
// ... 생략

export const deleteTodoApi
    = (username, id) => apiClient.delete(`/users/${username}/todos/${id}`)
```
* `deleteTodoApi`에서 `username`, `id`를 받아와서 `delete()` 메서드를 활용
* 해당 URL에 `DELETE` 메서드를 요청한다.

`ListTodosComponent.jsx`
```javascript
import { useEffect, useState } from "react";
import { retrieveAllTodosForUsername } from "./api/TodoApiService";

export default function ListTodosComponent() {

    // ... 생략
    function refreshTodos() {
        
        retrieveAllTodosForUsernameApi('Hyun')
        .then(response => {
            setTodos(response.data)
        })
        .catch(error => console.log(error))
    }

    function deleteTodo(id) {
        deleteTodoApi('Hyun', id)
        .then(() => {
                setMessage(`Delete of todo with ${id} successful`)
                refreshTodos()
            })
        .catch(error => console.log(error))
    }

    return (
    // ... 생략
        <tbody>
            {
                todos.map((todo) => (
                        <tr key={todo.id}>
                            <td>{todo.description}</td>
                            <td>{todo.done.toString()}</td>
                            <td>{todo.targetDate.toString()}</td>
                            <td><button 
                                    className="btn btn-warning" 
                                    onClick={() => deleteTodo(todo.id)}
                                >
                                    Delete
                                </button>
                            </td>
                        </tr>
                    )
                )
            }
        </tbody>
    // ... 생략
    )
}
```
* `deleteTodo`에서 `id`를 파라미터로 받은 후, Api에 `username`, `id`를 파라미터로 넣는다
    * `refreshTodos`는 삭제된 후의 목록을 반환하기 위한 목적.
* 삭제 버든을 만들고, `onClick` 으로 `deleteTodo()`에 파라미터에 `todo.id`를 지정
* 버튼을 클릭하면, id를 반환하는 것을 볼 수 있다.
![check-id-on-console](./img/check-id-on-console.png)
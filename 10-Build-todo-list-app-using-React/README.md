# 노트

## 1. React로 할 일 관리 앱 구축 시작하기
#### 투두 매니지먼트 앱 - 첫 스텝
1. Counter Example - 무엇을 배웠을까?
    * 컴포넌트 기본
        * View (JSX)
        * Styling (CSS)
        * State
        * Props
2. Todo 매니지먼트 앱 - 무엇을 배울까?
    * 라우팅
    * 폼
    * 데이터 검증
    * REST API 호출
    * 기본 인증, JWT 토큰 활용 인증
#### 컴포넌트
* Todo App 
    * Login Component
    * Welcome Component
    * Error Component
    * ListTodos Component
    * Header Component
    * Footer Component
    * Logout Component

## 2. 로그인 컴포넌트 시작하기 - Todo React 앱
#### Todo App 시작하기
1. Login Component
2. Welcome Component

* 모든 로직을 `TodoApp.jsx`에 작성한 뒤, 컴포넌트 분리 진행

`TodoApp.jsx`
```javascript
export default function TodoApp() {
    return(
        <div className="TodoApp">
            Todo Management Application
            <LoginComponent />
            {/* <WelcomeComponent /> */}
        </div>
    )
}

function LoginComponent() {
    return(
        <div className="Login">
            <div className="LoginForm">
                <div>
                    <label>User Name</label>
                    <input type="text" name="username" />
                </div>
                <div>
                    <label>Password</label>
                    <input type="password" name="password" />
                </div>
                <div>
                    <button type="button" name="login">login</button>
                </div>
            </div>
        </div>
    )
}

function WelcomeComponent() {
    return (
        <div className="Welcome">
            Welcome Componenet
        </div>
    )
}
```

## 3. 로그인 컴포넌트 개선

`TodoApp.jsx`
```javascript
// ... 생략 
function LoginComponent() {
    return(
        <div className="Login">
            <div className="LoginForm">
                <div>
                    <label>User Name:</label>
                    <input type="text" name="username" value="Hyun" />
                </div>
                <div>
                    <label>Password:</label>
                    <input type="password" name="password" />
                </div>
                <div>
                    <button type="button" name="login">login</button>
                </div>
            </div>
        </div>
    )
}
// ... 생략 
```
* `input` 태그의 `value`에 값을 입력하면, input에 자동으로 값이 채워지게 된다
* 하지만, 값을 바꾸려해도 바꿀수가 없다.
* 콘솔창에 제어할 수 없는 입력 값을 바꾸려고한다는 에러가 뜬다
![input-tag-value](./img/input-tag-value.png)

#### 제어 컴포넌트
* 리액트에서 `input` 태그에 `value` 값 지정시, 그 값이 입력 필드에 반영되지만 직접 수정하는 것은 불가능하다. 이는 제어 컴포넌트에 해당하기 때문이다.
* 리액트에서 `Form` 요소를 다룰 때, 유의할 사항
    * 제어 컴포넌트
        * `useState`를 사용하여 입력 값을 상태로 관리
        * `value`를 상태 값으로 설정하고, `onChange` 핸들러를 통해 상태를 변경하여 입력 값 업데이트
    * 비 제어 컴포넌트
        * `useRef`를 사용하여 직접 DOM을 조작
        * `defaultValue`를 활용하여 초기 값만 설정하고, 이후에는 리액트 상태가 아닌 DOM이 관리

#### 개선하기
`TodoApp.jsx`
```javascript
// ... 생략 
function LoginComponent() {
    const [username, setUsername] = useState('Hyun')
    const [password, setPassword] = useState('')

    return(
        <div className="Login">
            <div className="LoginForm">
                <div>
                    <label>UserName:</label>
                    <input type="text" name="username" value={username} 
                    onChange={(e) => {setUsername(e.target.value)}}/>
                </div>
                <div>
                    <label>Password:</label>
                    <input type="password" name="password" value={password}
                    onChange={(e) => {setPassword(e.target.value)}}/>
                </div>
                <div>
                    <button type="button" name="login">login</button>
                </div>
            </div>
        </div>
    )
}
// ... 생략 
```
* `useState`로 username, password를 미리 설정한다
* 이를 `input` 태그의 `value` 값에 넣는다.
* `onChange` 핸들러, `useState`의 변경 함수를 이용하여 `input` 태그의 `value` 값을 실시간으로 변경한다.

## 4. 하드 코딩으로 인증 추가 - Todo React 앱

#### 사용자 인증을 추가해보자.
* 일단 하드코딩으로 인증을 진행한다.
* 나중에 Spring Security를 사용하여 인증 진행.

```javascript
function LoginComponent() {

    // ... 생략
    const [showSuccessMessage, setShowSuccessMessage] = useState(false)
    const [showErrorMessage, setShowErrorMessage] = useState(false)

    function handleSubmit() {
        if(username==='Hyun' && password ==='dummy') {
            setShowSuccessMessage(true)
            setShowErrorMessage(false)
        } else {
            setShowSuccessMessage(false)
            setShowErrorMessage(true)
        }
    }

    function SuccessMessageConponent() {
        if (showSuccessMessage === true) {
            return <div className='successMessage'>Authenticated Successfully</div>
        }
        return null
    }

    function ErrorMessageComponent() {
        if (showErrorMessage === true) {
            return <div className='errorMessage'>Authenticated Failed. Please check your credentials.</div>
        }
        return null
    }
    // ... 생략
    return(
        <div className="Login">
            <SuccessMessageConponent />
            <ErrorMessageComponent />
            <div className="LoginForm">
                {/* ... 생략 */}
                <div>
                    <button type="button" name="login" onClick={handleSubmit}>login</button>
                </div>
            </div>
        </div>
    )
}
```
* `useState`로 Message 상태를 관리한다 (true, false)
* `handleSubmit` 함수를 만든다 (특정 username, password에 true, false를 지정)
    * 이를 `button` 태그에 있는 `onClick`에 지정
* 성공, 에러 메시지를 띄우는 함수를 만든다 `SuccessMessageConponent`, `ErrorMessageComponent`
* 
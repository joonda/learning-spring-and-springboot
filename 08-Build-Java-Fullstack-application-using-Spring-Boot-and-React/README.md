# 노트

## 1. 풀스택 Spring Boot와 React 애플리케이션
* ECMA 스크립트의 등장으로 JavaScript를 작성하기가 아주 쉬워졌다. 
* React Framework
    * Components
    * State
    * Routing
* REST API
* Authentication
* e.g.
    * Counter Example
    * Todo Management App
* 리액트에 대해서 이해하는 것이 필요.
* 리액트 기초에 익숙해지는 것.
    * Add Todo
    * Delete Todo
    * Update Todo
    * Authentication (Login/Logout)
    * JWT

## 2. 풀 스택 아키텍처는 무엇이며 왜 필요한가
* Front-end: React Framework
    * Modern JavaScript
* Backend REST API: Spring Boot
* Database
    * H2 > MySQL
* Authentication
    * Spring Security (Basic > JWT)

#### 왜 풀스택인가?
* 유연성이 높고, REST API를 사용할 수 있다.
    * REST API 비즈니스 로직 재사용 가능
        * REST API와 소통하는 모바일 애플리케이션도 만들 수 있다.
        * 또한 IoT앱도 REST API와 통신하도록 만들 수 있다.
    
## 3. JavaScript와 ECMA Script의 역사 이해하기
* 자바스크립트의 초기 버전에는 유지 보수할 수 있는 JavaScript 코드를 짜는 것이 매우 어려웠음
* 초기의 자바스크립트 코드는 DOM (문서 객체 모델) 다루는데 사용.
    * 코드 작성하기가 어려우며, 일정 기간 관리하는 것도 어려웠다.
    * ES5, ES6, ES7 등 이후 버전이 나오면서 매우 좋아졌다.
* ES : ECMASCRIPT
    * EcmaScript는 표준
    * JavaScript는 표준을 구현한 것이다.

## 4. Visual Studio Code 설치
* 확장성이 넓은 IDE이다.

## 5. Node.js와 npm설치
* [node.js 설치 페이지](https://nodejs.org/ko/download)
* nodejs, npm은 최신버전 유지를 추천한다.
* 만약 설치에 문제가 있다면, npm troubleshooting 을 검색해보자.
* node.js
    * 자바스크립트 코드를 브라우저 없이 기기에서 바로 실행할 수 있는 것
* npm
    * 자바스크립트의 패키지 관리자
        * 자바의 maven, gradle의 개념.
    * 종속성 추가
    * `package.json`
```terminal
npm init
```
* 모든 값을 기본 값으로 준 후, `yes`를 입력하면, `package.json`파일이 생성된다.

## 6. Create React App으로 React 앱 생성하기
* 리액트
    * 단일 페이지 애플리케이션 (SPA) 구축에 가장 인기있는 자바스크립트 라이브러리 중 하나이다.
    * 페이스북이 만든 오픈 소스 프로젝트
    * 컴포넌트의 조합으로 애플리케이션을 만든다 
    * React Native로 Android, iOS 앱도 만들 수 있다.
* 단일 페이지 애플리케이션 ?
    * 페이지에서 변경되는 해당 팥만 새로 고침
* npm vs. npx
    * npm : 패키지 매니저
    * npx : 패키지 실행 도구

```terminal
npx create-react-app todo-app
```

## 7. 중요한 Node.js 명령어 살펴보기 Create-react-app
* `npm start`
    * 리액트 앱 실행, Chrome 브라우저 권장
* `npm test`
    * 유닛 단위 테스트 진행
* `npm run build`
    * 최적화된 프로덕션 빌드를 생성
    * 중요한 파일은 js,css
* `npm install`
    * 특정 종속성을 설치

## 8. Visual Studio Code와 Create React App 살펴보기
* `Command+P` -> 특정 파일 오픈
* `Command+B` -> explorer 탭 여닫기

## 9. Create React App의 폴더 구조 살펴보기
* `README.md`: 문서
* `package.json`: 종속성을 정의하는 파일 (Maven의 pom.xml과 유사)
* `node_modules`: 모든 종속성이 다운로드 되는 폴더
* `React initialization`
    * `public/index.html`: root div 포함
    * `src/index.js`: 리액트 앱 초기화, 컴포넌트 로딩
    * `src/App.js`: 앱 컴포넌트를 위한 코드

## 10. React 컴포넌트 시작하기
* 웹 애플리케이션은 복잡한 구조를 띠고있다.
    * 메뉴, 헤더, 푸터, 웰컴 페이지, 로그인 페이지, 로그아웃 페이지, ...
* 리액트를 사용하면 각 페이지 요소에 별도 컴포넌트를 만든다.
    * 메뉴 컴포넌트
    * 헤더 컴포넌트
    * 푸터 컴포넌트 등...
* 왜?
    * 모듈화
    * 재사용
* View (JSX or JavaScript)
* Logic (JavaScript)
* Styling (CSS)
* State (Internal Data Store)
* Props (Pass Data)

## 11. 첫 번째 React 컴포넌트 생성
* 함수형 컴포넌트
```javascript
function FirstComponent() {
  return (
    <div className='FirstComponent'>First Component</div>
  )
}
```

* 클래스형 컴포넌트
```javascript
class ThirdComponent extends Component {
  render() {
    return (
    <div className='ThirdComponent'>Third Component</div>
  )}
}
```

* 요즘 React 생태계에서는 함수형 컴포넌트를 더 많이 쓴다.

## 12. React에서 State 시작하기 - Hook으로 State 사용하기
* State: 리액트에서 만든 각 컴포넌트에는 State라는 게 존재한다.
    * 특정 컴포넌트에 대한 데이터 및 정보
* 리액트 초기 버전에는 클래스 컴포넌트만 State를 가질 수 있었다.
* `Hooks`가 React 16.8 부터 나오기 시작, 함수형 컴포넌트에서도 State를 추가할 수 있게 되었다.
* 결국엔 함수형 컴포넌트를 대부분 쓰게 됐다.

## 13. JSX 탐색 - React 뷰
* 대부분의 리액트 프로젝트는 JSX로 보여준다.
    * JSX -> JavaScript XML의 약자이다.
* HTML보다 더 엄격하다
    * 닫는 태그가 필수적이다
    * 최상위 태그는 하나만 가능
        * 여러개 최상위 태그가 있을 수 없고 같은 부모태그로 묶어줘야한다. (e.g. `<></>, <div></div>`)
* 리액트 프로젝트에서 JSX가 어떻게 활성화 될까?
    * 브라우저마다 최신 기능에 대한 지원이 다르다.
        * ES2015, ... , ES2022, ...
        * 어떻게 JS 코드에 대한 호환성을 보장할 수 있을까?
            * Babel은 현대 자바스크립트 코드를 작성해도, 옛날 브라우저에서 실행될 수 있도록 해준다. (현대 자바스크립트 코드의 호환성 보장)
            * Babel은 또한 JSX를 JS로 변환해준다.
* [Babel 홈페이지](https://babeljs.io/)
    * 어떤 코드를 작성하든, 브라우저 호환 가능한 JavaScript로 변환된다.
* JSX를 반환할 때, return 하는 줄에 반드시 첫 번째 요소가 있어야 반환된다.
```javascript
function App() {
    return <div className="App">
        <FirstComponent />
        <SecondComponent />
        <ThirdComponent />
        <FourthComponent />
    </div>
}
```

* 아니면 일반적으로 괄호를 사용하는 것도 방법

```javascript
function App() {
    return (
        <div className="App">
            <FirstComponent />
            <SecondComponent />
            <ThirdComponent />
            <FourthComponent />
        </div>
    )
}
```

## 14. JavaScript 모범 사례 따라하기 - 모듈로 리팩토링
* 각 컴포넌트는 모듈화하는 것이 좋다
* `src/components/learning-examples` 해당 경로에 `FirstComponent.jsx`를 추가한다.
`FirstComponent.jsx`
```jsx
export default function FirstComponent() {
    return (
      <div className='FirstComponent'>First Component</div>
    )
}
```
* 모듈화 할때는 `export default`가 붙어있어야 한다.
`App.js`
```javascript
// ... 생략
import FirstComponent from './components/learning-examples/FirstComponent'

function App() {
  return (
    <div className="App">
      <FirstComponent />
      <SecondComponent />
      <ThirdComponent />
      <FourthComponent />
    </div>
  );
}

// ... 생략
```

* 컴포넌트화 한 모듈에서는 export할 때 `default`를 한개만 지정 가능하다
```javascript
export default function FirstComponent() {
    return (
      <div className='FirstComponent'>First Component</div>
    )
}
// default는 한개만 가능하다.
export function FifthComponent() {
  return (
    <div className='FirstComponent'>Fifth Component</div>
  )
}
```

* import 시에는 export하는 컴포넌트가 2개 이상이면 `{}`를 사용한다.
* `{}`가 없을시에는 `default`로 지정된 컴포넌트로 인식하여 import 된다.
```javascript
import {FifthComponent} from './root' 
```

* 모듈이 많다면, 흩어져있는 모듈을 합친 모듈을 만들어서 import하여 간단하게 만드는 방법도 있다.

`LearningComponent.jsx`
```javascript
import FirstComponent from './FirstComponent'
import SecondComponent from './SecondComponent';
import ThirdComponent from './ThirdComponent';
import FourthComponent from './FourthComponent';
import {FifthComponent} from './FirstComponent';


export default function LearningComponent() {
  return (
    <div className="App">
      <FirstComponent />
      <SecondComponent />
      <ThirdComponent />
      <FourthComponent />
      <FifthComponent />
    </div>
  );
}
```

`App.js`
```javascript
import './App.css';
// import FirstComponent from './components/learning-examples/FirstComponent'
// import SecondComponent from './components/learning-examples/SecondComponent';
// import ThirdComponent from './components/learning-examples/ThirdComponent';
// import FourthComponent from './components/learning-examples/FourthComponent';
// import {FifthComponent} from './components/learning-examples/FirstComponent';
import LearningComponent from './components/learning-examples/LearningComponent';

function App() {
  return (
    <div className="App">
      <LearningComponent />
    </div>
  );
}

export default App;
```

## 15. 향후 JavaScript
* 변수를 넣을 때는 `{}`를 사용한다.
`LearningJavaScript`
```javascript
const person = {
    name: "Hyun",
    address: {
        line1: "GangSeo",
        City: "Seoul",
        Country: "Republic of Korea"
    },
    profiles: ['twitter', 'linkedin', 'github'],

    // arrow function
    printProfile: () => {
        person.profiles.map(
            (profile) => {
                console.log(profile)
            }
        )
    }
}

export default function LearningJavaScript() {
    return (
        <>
            <div>{person.name}</div>
            <div>{person.address.Country}, {person.address.City}, {person.address.line1}</div>
            <div>{person.profiles[0]}</div>
            <div>{person.profiles[1]}</div>
            <div>{person.profiles[2]}</div>
            <div>{person.printProfile()}</div>
        </>
    )
}
```
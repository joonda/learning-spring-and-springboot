# 노트

## 1. 카운터 예제를 통해 React 컴포넌트 살펴보기
* 컴포넌트에 대해서 알아보기
    * View (JSX or Javascript)
    * Logic (JavaScript)
    * Styling (CSS)
    * State (내부 데이터 저장)
    * Props (데이터 전달)
* 카운터 예제를 통해 하나씩 구현

## 2. React 애플리케이션 시작하기 - Counter
```javascript
export default function Counter() {
    
    function incrementCounterFunction() {
        console.log('increment clicked')
    }
    
    return (
        <div className="Counter">
            <span className="count">0</span>
            <button className="counterButton" onClick={incrementCounterFunction}>increment</button>
        </div>
    )
}
```
* `onClick` 리스너로 function을 지정한다. 단, `incrementCounterFunction()`로 하기 되면 결과값만 호출되고 버튼을 클릭해도 아무런 반응이 없다
* `incrementCounterFunction` 이렇게 넣어야  버튼을 클릭했을 때 console 값에서 제대로 된 값을 확인할 수 있다.

## 3. React 애플리케이션 시작하기 - Counter-2
```javascript
export default function Counter() {

    const buttonStyle = {
        fontSize:"16px",
        backgroundColor:"#00a5ab",
        width:"100px",
        margin:"10px",
        color: "white",
        padding: "15px",
        borderRadius: "30px"
    }
    
    function incrementCounterFunction() {
        console.log('increment clicked')
    }
    
    return (
        <div className="Counter">
            <span className="count">0</span>
            <div>
                <button className="counterButton" 
                        onClick={incrementCounterFunction}
                        style={buttonStyle}
                
                >+1</button>
            </div>
        </div>
    )
}
```
* 이렇게 buttonStyle을 변수로 지정해 style에 넣을 순 있으나, CSS 파일을 만드는 방법을 권장한다.

`Counter.jsx`
```jsx
import './Counter.css'

export default function Counter() {
    
    function incrementCounterFunction() {
        console.log('increment clicked')
    }
    
    return (
        <div className="Counter">
            <span className="count">0</span>
            <div>
                <button className="counterButton" 
                        onClick={incrementCounterFunction}
                >+1</button>
            </div>
        </div>
    )
}
```

`Counter.css`
```css
.counterButton {
    font-size:16px;
    background-color: #00a5ab;
    width: 100px;
    margin: 10px;
    color: white;
    padding: 15px;
    border-radius: 30px;
    border-color: black;
    border-width: 1px;
}

.count {
    font-size: 150px;
    padding: 20px;
}
```
![counter-styling](./img/counter-styling.png)
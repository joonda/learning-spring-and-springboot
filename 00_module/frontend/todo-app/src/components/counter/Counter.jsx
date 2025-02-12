import { useState } from 'react'
import './Counter.css'
import CounterButton from './CounterButton';
import ResetButton from './ResetButton';

export default function Counter() {

    const [count, setCount] = useState(0);

    function incrementCounterFunction(by) {
        setCount(count+by)
    }

    function decrementCounterFunction(by) {
        setCount(count-by)
    }

    function resetCounterFunction() {
        setCount(0)
    }

    return (
        <>
            <CounterButton by={1} incrementCounterMethod={incrementCounterFunction} decrementCounterMethod={decrementCounterFunction}/>
            <CounterButton by={2} incrementCounterMethod={incrementCounterFunction} decrementCounterMethod={decrementCounterFunction}/>
            <CounterButton by={5} incrementCounterMethod={incrementCounterFunction} decrementCounterMethod={decrementCounterFunction}/>
            <span className='totalCount'>{count}</span>
            <ResetButton resetCounterMethod={resetCounterFunction}/>
        </>
    )
}


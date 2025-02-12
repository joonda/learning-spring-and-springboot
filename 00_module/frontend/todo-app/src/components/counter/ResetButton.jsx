import './Counter.css'

export default function ResetButton({resetCounterMethod}) {

    return (
        <div>
            <button
                className='resetButton'
                onClick={() => resetCounterMethod()}
            >Reset</button>
        </div>
    )
}
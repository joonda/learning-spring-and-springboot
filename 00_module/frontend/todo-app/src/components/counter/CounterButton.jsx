import PropTypes from 'prop-types';

export default function CounterButton({by, incrementCounterMethod, decrementCounterMethod}) {
    return (
        <div className="Counter">
            <div>
                <button className="counterButton" 
                        onClick={() => incrementCounterMethod(by)}
                >+{by}</button>
                <button className="counterButton" 
                        onClick={() => decrementCounterMethod(by)}
                >-{by}</button>
            </div>
        </div>
    )
}

CounterButton.propTypes = {
    by: PropTypes.number.isRequired, // by는 숫자이며 필수 props
};

  
CounterButton.defaultProps = {
    by: 1,
};
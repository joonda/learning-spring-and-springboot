import { useState } from 'react';
import './TodoApp.css';

export default function TodoApp() {
    return(
        <div className="TodoApp">
            <LoginComponent />
            {/* <WelcomeComponent /> */}
        </div>
    )
}

function LoginComponent() {

    const [username, setUsername] = useState('Hyun')
    const [password, setPassword] = useState('')
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

    return(
        <div className="Login">
            <SuccessMessageConponent />
            <ErrorMessageComponent />
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
                    <button type="button" name="login" onClick={handleSubmit}>login</button>
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
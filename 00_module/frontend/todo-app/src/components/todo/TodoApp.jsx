import { useState } from 'react';
import { BrowserRouter, Route, Routes, useNavigate } from 'react-router-dom';
import './TodoApp.css';

export default function TodoApp() {
    return(
        <div className="TodoApp">
            <BrowserRouter>
                <Routes>
                    <Route path='/' element={<LoginComponent />}></Route>
                    <Route path='login' element={<LoginComponent />}></Route>
                    <Route path='welcome' element={<WelcomeComponent />}></Route>
                </Routes>
            </BrowserRouter>
        </div>
    )
}

function LoginComponent() {

    const [username, setUsername] = useState('Hyun')
    const [password, setPassword] = useState('')
    const [showSuccessMessage, setShowSuccessMessage] = useState(false)
    const [showErrorMessage, setShowErrorMessage] = useState(false)
    const navigate = useNavigate();

    function handleSubmit() {
        if(username==='Hyun' && password ==='dummy') {
            setShowSuccessMessage(true)
            setShowErrorMessage(false)
            navigate('/welcome')
        } else {
            setShowSuccessMessage(false)
            setShowErrorMessage(true)
        }
    }
    return(
        <div className="Login">
            {showSuccessMessage && <div className='successMessage'>Authenticated Successfully</div>}
            {showErrorMessage && <div className='errorMessage'>Authenticated Failed. Please check your credentials.</div>}
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
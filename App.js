
import React, {useState} from "react";

function App(){
  const [user,setUser]=useState("");
  const [pass,setPass]=useState("");

  const signup=()=>{
    fetch("http://localhost:18080/signup",{
      method:"POST",
      body:JSON.stringify({user,pass})
    });
  };

  const login=()=>{
    fetch("http://localhost:18080/login",{
      method:"POST",
      body:JSON.stringify({user,pass})
    }).then(r=>alert("Logged in"));
  };

  return(
    <div>
      <h1>Login</h1>
      <input placeholder="user" onChange={e=>setUser(e.target.value)}/>
      <input placeholder="pass" onChange={e=>setPass(e.target.value)}/>
      <button onClick={signup}>Signup</button>
      <button onClick={login}>Login</button>
    </div>
  );
}
export default App;

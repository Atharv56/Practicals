import React, { useState } from "react";

function Counter(){
    const [vishma, vrajesh] = useState(0)
    const handleIncrement = () => {
        vrajesh(vishma + 1)

    }
    const handleDecrement = () =>{
        vrajesh(vishma - 1)
    }
    return(
        <div>
            <h1>Count: {vishma}</h1>
            <button onClick={handleIncrement}>Increment</button>
            <button onClick={handleDecrement}>Decrement</button>
        </div>
    )
}

export default Counter


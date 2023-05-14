function display(val) {
    document.getElementById("result").value += val;
    return val;
    }
    function solve() {
    let x = document.getElementById("result").value;
    let y = 0;
    if (x.includes("Sqrt")) {
    let number = x.split("Sqrt");
    let result = parseInt(number[1]);
    console.log(number);
    y = Math.sqrt(result);
    } else if (x.includes("log")) {
    let result = x.split("log");
    let number = parseInt(result[1]);
    y = Math.log(number);
    } else if (x.includes("^")) {
    let result = x.split("^");
    y = Math.pow(parseInt(result[0]), parseInt(result[1]));
    } else {
    y = eval(x);
    }
    document.getElementById("result").value = y;
    return y;
    }
    function clearScreen() {
    document.getElementById("result").value = "";
    }
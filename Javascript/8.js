const oddOrEven = (n) => {
    let a = n.toString();
    let b = 0;
    for (let i = 0; i < a.length; i++) {
    b += parseInt(a[i]);
    }
    if (b % 2 === 1) {
    return "Odd";
    } else return "Even";
    };
console.log(oddOrEven(45));
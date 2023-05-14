const q9 = (n) => {
    let a = n.toString();
    let b = 0;
    let count = a.length;
    for (let i = 0; i < a.length; i++) {
    b += parseInt(a[i]);
    }
    console.log(b, count);
    };
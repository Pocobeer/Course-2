// console.log(`'7'+7 =>`);
// console.log('7'+7);
// console.log(`'7'-false=>`);
// console.log('7' - false);
// console.log(`4/0=>`);
// console.log(4/[]);
// console.log(`4+'cat'=>`);
// console.log(4+'cat');
// console.log(`3/0=>`);
// console.log(3/0);
// console.log(`3 Задание: for(var i = 0, n; i < 10; i++){
//     n = i;
//     delete i;
//     n == ?
// }`);
// for(var i = 0, n; i < 10; i++){
//     n = i;
//     delete i;
// }
// console.log(n);
// console.log(`4 задание:
// var f = function(){return typeof 25;};
// console.log(typeof f.name()); - ОШИБКА`);
// var f = function(){return typeof 25;};
// //console.log(typeof f.name());
// console.log(`5 задание:
// var str = "20";
// str[1] = "5";
// let data = -str +2;`)
// var str = "20";
// console.log(str);
// str[1] = "5";
// console.log(str);
// let data = -str +2;
// console.log(data);
// console.log(`8 задание: 
// function MyConstructor(arr){
//     for(var nProp = 0; nProp < arr.length; nProp++)
//         this['priperty' + nProp] = arr[nProp];
//     return nProp;
// }
// function look(){
//        var str = '';
//     for(const p in this)
//         str += (p+'='+this[p]+'\n');
//     return str;
// }
// var myArray = new MyConstructor(4, 'Привет, мир!', false);
// var myInstance = myConstructor(myArray);
// console.log(myInstance);
// console.log(look.call(myInstance)); - ОШИБКА
// `)
// function MyConstructor(arr){
//     for(var nProp = 0; nProp < arr.length; nProp++)
//         this['priperty' + nProp] = arr[nProp];
//     return nProp;
// }
// function look(){
//        var str = '';
//     for(const p in this)
//         str += (p+'='+this[p]+'\n');
//     return str;
// }
// var myArray = new MyConstructor(4, 'Привет, мир!', false);
// var myInstance = myConstructor(myArray);
// console.log(myInstance);
// console.log(look.call(myInstance));
// console.log(`9 задание:
// function flexisum(){
//     var total = 0;
//     for(var i = 0; i < arguments.length; i++){
//         var element = arguments[i], n;
//         if(typeof element === 'object')
//             n = flexisum.apply(this, element);
//         else
//             if(typeof element === 'function')
//                 n = element();
//             else n = element;
//         if (inNaN(n)) n = 0;
//         total += n;
//     }
//     return total;
//     flexisum(2, [5, '6'], '2+2')
//     flexisum(5, function(){return '25'}, '0')
// }`);
// function flexisum(){
//     var total = 0;
//     for(var i = 0; i < arguments.length; i++){
//         var element = arguments[i], n;
//         if(typeof element === 'object')
//             n = flexisum.apply(this, element);
//         else
//             if(typeof element === 'function')
//                 n = element();
//             else n = element;
//         if (inNaN(n)) n = 0;
//         total += n;
//     }
//     return total;
// }
// console.log(flexisum(2, [5, '6'], '2+2'))
// console.log(flexisum(5, function(){return '25'}, '0'))
// console.log(`10 задание:
// function sum_3_2(){
//     if (!(n in sum_3_2))
//         sum_3_2[n] = sum_3_2[0] + sum_3_2(n-1);
//     return sum_3_2[n];
// }
// sum_3_2[0] = -2;
// sum_3_2[1] = -3;
// console.log(sum_3_2(4));
// console.log(sum_3_2[4]);
// `)
function sum_3_2(n){
    if (!(n in sum_3_2))
        sum_3_2[n] = sum_3_2[0] + sum_3_2(n-1);
    return sum_3_2[n];
}
sum_3_2[0] = -2;
sum_3_2[1] = 3;
console.log(sum_3_2(4));
console.log(sum_3_2(5));
// console.log(`11 задание:
// let max, min = 10;
// function f(a){
//     console.log(max);
//     var max = Math.max(a[0], a[1]);
//     console.log(max);
//     console.log(min);
//     min = Math.min(a[0], a[1]);
//     console.log(min);
// }
// f([5,3]);
// `)
// let max, min = 10;
// function f(a){
//     console.log(max);
//     var max = Math.max(a[0], a[1]);
//     console.log(max);
//     console.log(min);
//     min = Math.min(a[0], a[1]);
//     console.log(min);
// }
// f([5,3]);
// console.log(`12 задание:
// var m = {a: 1,
//     b: "cat"},
//     k = {};
// k = m;
// m.a = 0;
// for(const p in k){
//     k[p] += 13;
// }
// `)
// var m = {a: 1,
//     b: "cat"},
//     k = {};
// k = m;
// m.a = 0;
// for(const p in k){
//     k[p] += 13;
// }
// console.log(m);
// console.log(`13 задание:
// function userId ({fullName:{id}})(return id;)
// function whois ({displayName: dN, fullName: {firstName: fN}})
// {
//     console.log('${dN.toLowerCase()} is ${fN.toUpperCase()}');
// }
// const A = {displayName: "jdoe",
//     id: 42,
//     fullName: {
//         firstName: "John",
//         lastName: "Doe"
//         id: "JD_42",
//     },
// };
// console.log('Id: ${userId(A)}');
// whois(A);
// `)
// //function userId ({fullName:{id}))(return id;)}
// function whois ({displayName: dN, fullName: {firstName: fN}})
// {
//     console.log(`${dN.toLowerCase()} is ${fN.toUpperCase()}`);
// }
// const A = {displayName: "jdoe",
//     id: 42,
//     fullName: {
//         firstName: "John",
//         lastName: "Doe",
//         id: "JD_42",
//     },
// };
// console.log(`Id: ${userId(A)}`);
// whois(A);
// console.log(`14 задание:
// triangle.side = 4;
// console.log(triangle.S);
// triangle.S = 64;
// console.log(triangle.side);
// console.log(triangle.c);
// triangle.c = 100;
// `)
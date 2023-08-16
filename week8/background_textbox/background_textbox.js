function isColor(word) {

    const colors = [
        'red', 'orange', 'yellow', 'green', 'blue', 'indigo', 'violet',
        'black', 'white', 'gray', 'brown', 'pink', 'purple', 'cyan', 'magenta',
        'aqua', 'beige', 'coral', 'gold', 'ivory', 'khaki', 'lavender', 'lime',
        'maroon', 'navy', 'olive', 'plum', 'silver', 'teal', 'turquoise',
        'salmon', 'tan', 'chartreuse', 'crimson', 'fuchsia', 'orchid', 'peru',
        'rosybrown', 'skyblue', 'thistle', 'tomato', 'wheat', 'aliceblue',
        'antiquewhite', 'aquamarine', 'azure', 'bisque', 'blanchedalmond',
        'cadetblue', 'cornflowerblue', 'cornsilk', 'darkblue', 'darkcyan',
        'darkgoldenrod', 'darkgray', 'darkgreen', 'darkkhaki', 'darkmagenta',
        'darkolivegreen', 'darkorange', 'darkorchid', 'darkred', 'darksalmon',
        'darkseagreen', 'darkslateblue', 'darkslategray', 'darkturquoise',
        'darkviolet', 'deeppink', 'deepskyblue', 'dimgray', 'dodgerblue',
        'firebrick', 'floralwhite', 'forestgreen', 'gainsboro', 'ghostwhite',
        'goldenrod', 'greenyellow', 'honeydew', 'hotpink', 'indianred',
        'khaki', 'lavenderblush', 'lawngreen', 'lemonchiffon', 'lightblue',
        'lightcoral', 'lightcyan', 'lightgoldenrodyellow', 'lightgray',
        'lightgreen', 'lightpink', 'lightsalmon', 'lightseagreen',
        'lightskyblue', 'lightslategray', 'lightsteelblue', 'lightyellow',
        'limegreen', 'linen', 'mediumaquamarine', 'mediumblue', 'mediumorchid',
        'mediumpurple', 'mediumseagreen', 'mediumslateblue', 'mediumspringgreen',
        'mediumturquoise', 'mediumvioletred', 'midnightblue', 'mintcream',
        'mistyrose', 'moccasin', 'oldlace', 'olivedrab', 'orange',
        'orangered', 'palegoldenrod', 'palegreen', 'paleturquoise', 'palevioletred',
        'papayawhip', 'peachpuff', 'powderblue', 'rebeccapurple', 'rosybrown',
        'saddlebrown', 'sandybrown', 'seagreen', 'seashell', 'sienna', 'skyblue',
        'slateblue', 'slategray', 'snow', 'springgreen', 'steelblue', 'tan',
        'thistle', 'tomato', 'turquoise', 'violet', 'wheat', 'whitesmoke',
        'yellowgreen'
    ];


    const lowercaseWord = word.toLowerCase();


    if (colors.includes(lowercaseWord)) {
        return true;
    } else {
        return false;
    }
}
document.addEventListener("DOMContentLoaded", function () {
    let body = document.querySelector('body')
    let mycolor = document.querySelector("#text_box")
    document.querySelector("#button").addEventListener('click', function (event) {
        if (isColor(mycolor.value) == true) {
            body.style.background = mycolor.value;
        }
        else {
            alert("the color you entered is invalid color ");
        }
        event.preventDefault();
    });

});

document.addEventListener("DOMContentLoaded", function () {

    document.querySelector("#theered-answer").addEventListener('click', function (event) {
        let correct_button = document.querySelector("#theered-answer");

        correct_button.style.background = "green";
        document.querySelector("#first-answer").style.background = "red";
        document.querySelector("#seconed-answer").style.background = "red";
        document.querySelector("#fourth-answer").style.background = "red";
        document.getElementById("correct").style.visibility = "visible"
    });
});


document.addEventListener("DOMContentLoaded", function () {
    document.querySelector("#fourth-answer").addEventListener('click', function (event) {
        document.querySelector("#theered-answer").style.background = "green";
        document.querySelector("#first-answer").style.background = "red";
        document.querySelector("#seconed-answer").style.background = "red";
        document.querySelector("#fourth-answer").style.background = "red";
        document.getElementById("Incorrect").style.visibility = "visible"

    });
});

document.addEventListener("DOMContentLoaded", function () {
    document.querySelector("#text-button").addEventListener('click', function () {
        console.log(10);
        let answer = document.getElementById("text-answer");
        if(answer.value == 'Germany, Italy, and Japan'){
            answer.style.background="green";
            document.getElementById("correct1").style.visibility = "visible"
        }
        else{
            document.getElementById("Incorrect1").style.visibility = "visible"
            answer.style.background="red";
        }
    });
});
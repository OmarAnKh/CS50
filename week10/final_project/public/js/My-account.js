document.addEventListener("DOMContentLoaded", () => {
    document.getElementById('edit').addEventListener('click', () => {
        if (checkbox1) {
            document.getElementById('edit').style.visibility = 'hidden';
            document.getElementById('done').style.visibility = 'visible';
            const span = document.getElementById("info1");
            span.contentEditable = true;
            document.getElementById('done').addEventListener('click', () => {
                document.getElementById('edit').style.visibility = 'visible';
                document.getElementById('done').style.visibility = 'hidden';
                span.contentEditable = false;



                fetch('/update', {
                    method: 'PATCH',
                    headers: {


                    },
                    body: JSON.stringify({ 'name': span.innerText })
                })
            })
        }
    })
})
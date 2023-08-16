const products = [];
const product_amount = [];
let counter = 0;



document.addEventListener("DOMContentLoaded", function () {
    let pro_name = document.querySelector('#product_name');
    let pro_amount = document.querySelector('#amount_number');
    let list = document.querySelector('#list');
    let sidebar = document.querySelector('#mySidenav');
    document.querySelector('#add').addEventListener('click', function (event) {
        products.push(pro_name.value);
        product_amount.push(pro_amount.value);


        const listItem = document.createElement("ol");
        listItem.className = "list1";
        listItem.id = "title" + counter;

        list.appendChild(listItem);
        

        const box = document.createElement("span");
        box.id = "name" + counter;
        box.className = "span1";
        box.innerHTML = `${pro_name.value} ,      ${pro_amount.value}`;

        listItem.appendChild(box);
        

        const checkbox = document.createElement("input");
        checkbox.id = "pro" + counter;
        checkbox.type = "checkbox";
        checkbox.className = "checkboxs";

        listItem.appendChild(checkbox);
        sidebar.appendChild(listItem.cloneNode(true));
        
        counter++;

        event.preventDefault();
    });
});


document.addEventListener("DOMContentLoaded", function () {
    document.querySelector('#delete').addEventListener('click', function (event) {
        
        for (let i = 0; i < counter; i++) {
            var elementExists = document.getElementById("pro" + i)
            if (elementExists) {
                
                
                if (document.getElementById('pro' + i).checked ) {
                    var element = document.getElementById("title" + i);
                    element.parentNode.removeChild(element);
                    console.log(elementExists)
                }
            }
        }
        event.preventDefault();
    });
});


document.addEventListener("DOMContentLoaded", function () {
    const end_button = document.getElementById("done");
    let edit_counter = 0;
    document.querySelector('#edit').addEventListener('click', function (event) {

        let index;
        for (let i = 0; i < counter; i++) {
            var elementExists = document.getElementById("pro" + i)
            if (elementExists) {
                if (document.getElementById('pro' + i).checked) {
                    edit_counter++;
                    index = 'name' + i

                }
                console.log(edit_counter);
            }

        }
        if (edit_counter == 1) {
            document.getElementById('edit').style.visibility = 'hidden';
            document.getElementById('done').style.visibility = 'visible';
            const span = document.getElementById(index);
            span.contentEditable = true;
            span.style.backgroundColor = "#D6E4E5";
            end_button.addEventListener("click", function () {
                span.contentEditable = false;
                span.style.backgroundColor = "#D3D3D3";
                document.getElementById('edit').style.visibility = 'visible';
                document.getElementById('done').style.visibility = 'hidden';

            })
        }
        else {
            alert('you are trying to edit more than one product at a time ');
        }
        edit_counter = 0;
        event.preventDefault();
    });

});



function openNav() {
    document.getElementById("mySidenav").style.width = "600px";
}


function closeNav() {
    document.getElementById("mySidenav").style.width = "0px";
}
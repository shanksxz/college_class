// demo file


console.log("Demmo")


const demoObj = {
    name: "Demo",

    parent : {
        name : "Parent",
        child : {
            name : "Child",
            nestedChild : {
                name : "Nested Child"
            }
        }
    },

    printName: function () {
        console.log(this.name);
    }
}


const arr = [1,1,2,2,5]

function removeDuplicates(arr) {
    return [...new Set(arr)]
}


function removeDUp(arr) {
    const newArr = []
    arr.forEach((item) => {
        if(!newArr.includes(item)) {
            newArr.push(item)
        }
    })
    return newArr
}
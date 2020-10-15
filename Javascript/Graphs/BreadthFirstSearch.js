// Input
var size = 5; 

var paths = [
    [1, 2],
    [1, 4],
    [2, 3],
    [2, 5],
];


// Graph Implementation
const adjancencyList = new Map();

for(var i = 1; i <= size; i++) {
    adjancencyList.set(i, []);
}


function addEdge(s, e){
    adjancencyList.get(s).push(e);
    adjancencyList.get(e).push(s);
}

paths.forEach(paths => addEdge(...paths));


// Algorithm
function bfs(s, loc){
    
    const q = [s];
    const dist = new Array(6).fill(0);

    const visited = new Set(); // Initialize dynamic array

    while (q.length > 0){
        const f = q.shift(); // takes in the value at the front of the queue
        const paths = adjancencyList.get(f); // access nodes from adjancencyList[f]

        console.log(f);

        for (const path of paths){
            if (path == loc){
                console.log("Found!", loc)
                console.log(dist);
            }
            // A Set boolean that checks for already added nodes, since there
            // is no need to traverse the same node more than once.
            if (!visited.has(path)){ 
                dist[path] = dist[f] + 1;
                visited.add(path);
                q.push(path);
            }
        }
    }
}

bfs(5, 3);
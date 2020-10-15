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
function dfs(s, loc, visited = new Set(), dist = new Array(6).fill(0)){
    
    visited.add(s); // add visited node
    const paths = adjancencyList.get(s); // access nodes from adjancencyList[f]

    for (const path of paths){

        if (path == loc){
            console.log("Found!", loc)
            console.log(dist);
            return;
        }
        // A Set boolean that checks for already added nodes, since there
        // is no need to traverse the same node more than once.
        if (!visited.has(path)){
            dist[path] = dist[s] + 1;
            visited.add(path);

            // Recursion
            dfs(path, loc, visited, dist);
        }    
    }
}

dfs(5, 3);
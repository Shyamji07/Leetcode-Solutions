const countPairs = function(n, edges) {
    let g = Array(n).fill().map( _ => [] ), c = 0,
        f = ( e, z = g[e] ) => z ? ( g[e] = 0 ) || 1 + z.reduce( ( t, y ) => t + f(y), 0 ) : 0
    for ( let [ a, b ] of edges ) g[a].push(b), g[b].push(a)
    for ( let i = 0, v = 0, x = 0; i < n; i++, v += x ) c += ( x = f(i) ) * v
    return c
}
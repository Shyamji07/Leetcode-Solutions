const maximumRequests = ( n, requests ) => {
    const transfers = Array(n).fill(0)
    let max = 0
    
    const search = ( i, count ) => {
        if ( i === requests.length ) {
            if ( count > max && ! transfers.some( x => x ) )
                max = count
            return
        }

        transfers[ requests[i][0] ]--
        transfers[ requests[i][1] ]++
        search( i + 1, count + 1 )
        transfers[ requests[i][0] ]++
        transfers[ requests[i][1] ]--
        
        search( i + 1, count )
        
    }
    
    search( 0, 0 )
    
    return max
}
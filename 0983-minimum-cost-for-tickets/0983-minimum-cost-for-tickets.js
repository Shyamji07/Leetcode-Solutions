var mincostTickets = function(days, costs) {
        const [ _1day, _7day, _30day] = [0, 1, 2];
        let travelDays = new Set(days);
        let lastTravelDay = days[days.length-1];
    
    dpCost = new Array( lastTravelDay+1 ).fill(0);
    
    for( let day_i=1; day_i <= lastTravelDay ; day_i++ ){
        if( travelDays.has(day_i) == false ){
            dpCost[ day_i ] = dpCost[ day_i - 1 ];
            
        }
        else{
            dpCost[ day_i ] = Math.min( dpCost[ day_i - 1 ] + costs[ _1day ],
                                        dpCost[ Math.max(day_i - 7, 0) ] + costs[ _7day ], 
                                        dpCost[ Math.max(day_i - 30, 0) ] + costs[_30day]  );
        }
    }

    return dpCost[lastTravelDay];
    
};
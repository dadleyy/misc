-- Cards.lua --
-- Author: Danny Hadley
-- Date: Winter 2013

-- Global variables
deck, top, players = { }, 1, { }

-- Deck initialization
do 

local _suits, _values, _index = { }, { }, 1

_suits  = { "Hearts", "Diamonds", "Clubs", "Spades" }
_values = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
            "Nine", "Ten", "Jack", "Queen", "King", "Ace" }

-- _makeDeck 
-- Loops through suits and values, passing 
-- them into the "deck" global variable
-- @param {table} _deck A reference to a table that will be set
local function _makeDeck( _deck ) 
    print("---> Making the deck")
    if _deck == nil then _deck = { } end
    
    for i,suit in ipairs(_suits) do
        for j, value in ipairs(_values) do
            _deck[_index] = { value = j, suit = suit, rank = value }
            _index = _index + 1
            if DEBUG ~= nil then
                print("-> Made the " .. value .. " of " .. suit )
            end
        end
    end
    return _deck 
end

_makeDeck( deck )

print("-> Finished")

end

function log ( message, level )
    local _lvl, _msg = level or 2, ""
    
    for i=1,_lvl do _msg = _msg .. "-" end

    if DEBUG ~= nil then
        print( _msg.."> ".. message )    
    end
    
end

function rateCards ( hand, printOut ) 
    
    local _ratingFuncs, _found = { }, false



    -- tryStraight
    -- Checks the hand parameter for a straight
    -- @param {table} hand The whole hand to search through
    -- @returns {list|false} Returns the list of connected cards,
    -- or false, if less than 5 were found
    local function tryStraight ( hand ) 
        local _run, _past, _high, _result, _list, _ace = 1, { }, { }, { }, { }, false
        
        -- Push the first one in the straight list
        _high    = hand[1]
        _past    = { value = hand[1].value + 1, rank = "xxx", suit = "" } 
        
        for index, card in ipairs(hand) do
            local _value, _suit, _rank, _parent = card.value, card.suit, card.rank, false
                                 
            if _value == 14 then
                _ace = true
            end
                 
            -- If this card's value is one less than the past
            if _value + 1 == _past.value and _run <= 5 then
                
                if index ~= 1 and _run == 1 then
                    _list[_run] = { suit = _past.suit, rank = _past.rank, value = _past.value }
                    log("Pushing: ".._past.rank, 2)
                    _run = _run + 1
                end
            
                _list[_run] = { suit = _suit, rank = _rank, value = _value }
                
                _run = _run + 1  
                                
                log("Pushing: ".._rank, 2)
                
                _past = card
                
            elseif _value == _past.value then
                    
                local _suits = { _past.suit }
                if type( _past.suit ) == "table" then 
                    _suits = _past.suit 
                end
                
                table.insert( _suits, _suit )
                
                _past = { rank = _rank, value = _value, suit = _suits }
                
            else 
                
                log("Run ending on ".._rank)
                
                if _run < 6 then
                    _run  = 1
                    _list[_run] = { suit = _suit, rank = _rank, value = _value }
                end 
                
                _past = card
                                
            end
                
              
        end
        
        -- if an ace was there and the run ended in a 2
        if _ace and _past.value == 2 and _run == 5 then             
            -- _run = _run + 1
            _list[_run] = { suit = _past.suit, value = "14", rank = "Ace" }
            log("adding ace")
            _run = _run + 1
        end
    
        -- return the high card and the run if it was a straight
        if _run >= 5 then 
            _result = { high = _high.rank, run = _list } 
        else 
            _result = false
        end
        
        return _result
    end
    
    -- getPairs 
    local function getPairs ( hand )
        local _matches = { }
    
        for i=1,13 do _matches[i] = 0 end
    
        for index, card in ipairs(hand) do                  
            _matches[card.value] = _matches[card.value] + 1
        end
        
        return _matches
    end
    
    -- countSuited
    -- Counts the amount of suited cards in a given
    -- input table
    local function countSuited ( hand, matches ) 
        log("Counting the amount of suited cards...")   
        
        local _counts, _max = { }, { count = 0 }
        
        if matches ~= nil and type(matches) == "table" then
            _counts = matches
        end
        
        for index, card in ipairs(hand) do
            
            if type( card.suit ) == "table" then
                for index, ssuit in ipairs(card.suit) do
                
                    if _counts[ssuit] == nil then
                        _counts[ssuit] = 0
                    end
                    
                    _counts[ssuit] = _counts[ssuit] + 1
                    
                    if _counts[ssuit] > _max.count then
                        _max = { suit = ssuit, count = _counts[ssuit] }
                    end
                    
                end 
            else
                if _counts[card.suit] == nil then
                    _counts[card.suit] = 0
                end
                _counts[card.suit] = _counts[card.suit] + 1
                
                if _counts[card.suit] > _max.count then
                    _max = { suit = card.suit, count = _counts[card.suit] }
                end
            end 
        
        end
            
        for key, value in pairs(_counts) do
            log(value.." "..key.."'s",1)
        end
        
        return _max
    end
    
     
        
    -- ---------------------- --
    -- Straight flush checker --
    _ratingFuncs[1] = function ( hand ) 
        local _straight, _flush, _result = tryStraight( hand ), false, { }
        
        if _straight == false then
            return false
        end
                
        _flush = countSuited( _straight.run )
        
        if _flush.count < 5 then
            return false
        end
        
        _result = { name = "Straight flush with " .. _flush.suit .. " starting at ".._straight.run[1].rank  }
        
        return _result
    end


    -- ---------------------- --
    -- Four of a kind checker --
    _ratingFuncs[2] = function ( hand )
        
        local _result, _fourofakind = getPairs( hand ), false
        
        for k,v in pairs(_result) do
            if v == 4 then 
                _fourofakind = k
            end
        end
        
        if _fourofakind == false then
            return false
        end
        
        return { name = "Four of a kind with " .. toRank(_fourofakind) }
    end
    
    -- ---------------------- --
    -- Full House checker     --
    _ratingFuncs[3] = function ( hand )
    
        local _matches, _low, _high = getPairs( hand ), false, false
        
        for k,v in pairs(_matches) do
            if v == 3 then _high = k end
            if v == 2 then _low = k end
        end
        
        if _low == false or _high == false then
            return false
        end
            
        return { name = "Full house with ".. toRank(_low) .." low and ".. toRank(_high) .." high" } 
    end
    
    -- ---------------------- --
    -- Flush checker          --
    _ratingFuncs[4] = function ( hand )
    
        local _flush = countSuited( hand )
        
        if _flush.count < 5 then
            return false
        end
        
        return { name = "Flush with " .. _flush.suit } 
    end

    -- ---------------------- --
    -- Straight checker       --
    _ratingFuncs[5] = function ( hand )
    
        local _straight = tryStraight( hand )
        
        if _straight == false then
            return false
        end
                        
        return { name = "Straight starting at ".._straight.run[1].rank  }
        
    end
    
    
    -- ----------------------- --
    -- Three of a kind checker --
    _ratingFuncs[6] = function ( hand )
    
        local _matches, _low = getPairs( hand ), false
        
        for k,v in pairs(_matches) do
            if v == 3 then _low = k end
        end
        
        if _low == false then
            return false
        end
            
        return { name = "Three of a kind with ".. toRank(_low) } 
        
    end
    
    
    -- ----------------------- --
    -- Two pair checker        --
    _ratingFuncs[7] = function ( hand )
        
        local _matches, _pairs, _pairsets, _set = false, 0, { 0, 0 }, 0
        
        _matches = getPairs( hand )
        
        for i,j in ipairs(_pairsets) do     
            for k,v in pairs(_matches) do
                if v == 2 then 
                    
                    if i == 1 then
                        _pairs = _pairs + 1
                    end
                    
                    if k > j and k ~= _set then
                        j = k
                        if i == 1 then
                            _set = k
                        end
                    end
                end
            end 
            _pairsets[i] = j       
        end
    
        if _pairs < 2 then
            return false
        end
            
        return { name = "Two pairs with ".. toRank(_pairsets[1]) .. " and " .. toRank(_pairsets[2]) } 
        
    end
    
    
    -- ----------------------- --
    -- Pair checker            --
    _ratingFuncs[8] = function ( hand )
    
        local _matches, _pairs, _rank = getPairs( hand ), 0, 0
            
        for k,v in pairs(_matches) do
            if v == 2 then 
                if k > _rank then
                    _rank = k
                end
            end
        end            
        
        if _rank == 0 then
            return false
        end
            
        return { name = "A pair of ".. toRank(_rank) } 
        
    end
    
    -- ----------------------- --
    -- High card  checker      --
    _ratingFuncs[9] = function ( hand )
        return { name = "High card of " .. hand[1].rank }  
    end



    local function _sortByRank (card1, card2) 
        return card1.value > card2.value
    end
    
    table.sort(hand, _sortByRank)
    
    for name, fn in ipairs(_ratingFuncs) do
        _found = fn( hand )
        if _found ~= false then break end
    end
    
    if printOut ~= nil then 
        for index, card in ipairs(hand) do printCard(card) end
        print( "-> result: ".. _found.name )
    end
    
    return _found
end 

-- printCard
-- Prints a nice string for a specific
-- card out into the console
function printCard ( card, index ) 
    
    print("[".. (index or "-") .."] - "..card.rank.." of "..card.suit .. " ("..card.value..")")
end

-- printDeck
-- Loops through a the global deck variable
-- and prints out the name and suit of each card
function printDeck ( )
    print("--> Printing the deck:")
    for i,card in ipairs(deck) do
        printCard( card )
    end
end

-- dealCards 
-- Take the deck and deal them to the 
-- appropriate amount of players. 
-- @param {number} playerCount The amount of players in the game
-- @param {boolean} andShuffle A flag to include a shuffle if necessary
function dealCards ( playerCount, andShuffle )
    print("--> Dealing the cards")
    
    if andShuffle == true then
        print("-> Reshuffling cards")
        shuffleCards( true )
    end
    
    local _pcount = (type(playerCount) == "number") and playerCount or 2
    
    print("-> Dealing cards to " .. _pcount .. " Players" ) 
    
    for i=1,_pcount do
        local _name, _hand, _outcome = "Player "..i, { }, { }
        
        for j=1,7 do 
            local _card = deck[top]
            
            _hand[j] = _card
            
            top = top + 1        
        end
        
        -- calculate the outcome of this hand
        _outcome = rateCards( _hand )
        
        -- save the calculated outcome into the hand
        _hand.outcome = _outcome
        
        -- save the hand into the current player
        players[_name] = _hand
        

        printHand(i)
    end
    
    print("-> Top of deck: "..top)    
end

-- shuffleCards
-- Randomly shuffle the cards in the global "deck" 
-- variable and call dealCards if necessary
-- @param {boolean} noDeal Flag for not calling dealCards 
function shuffleCards ( noDeal ) 
    print("--> Shuffling cards")    
    -- _sorter 
    -- Sort the cards based on a random value
    -- set during shuffle
    local function _sorter (v1, v2)
        return v1.rand > v2.rand
    end
    
    math.randomseed( os.time() )    
    for i,card in ipairs(deck) do
        card.rand = math.random()
    end
    table.sort( deck, _sorter )
    
    if DEBUG ~= nil then
        printDeck( deck )
    end
    
    print("-> Finished")
    
    if noDeal == nil or noDeal == false then
        dealCards( 7, false )
    end
end


function toRank ( value )
    local _translation = { }
    
    _translation[13] = "Ace" 
    _translation[12] = "King"
    _translation[11] = "Queen" 
    _translation[10] = "Jack"
    _translation[9] = "Ten"
    _translation[8] = "Nine" 
    _translation[7] = "Eight"
    _translation[6] = "Seven"
    _translation[5] = "Six"
    _translation[4] = "Five"
    _translation[3] = "Four"
    _translation[2] = "Three"
    _translation[1] = "Two"

    return _translation[value] or value
    
end
        
        
-- printHand
-- Lists out a player's hand
function printHand ( name )
     
    if name == nil then 
        print("!-> need to supply the player name")
    end
    
    local _hand, _name = nil, name
    
    -- allow player's hand to be accessed by a number
    if type(_name) == "number" then
        _name = "Player ".._name
    end

    _hand = players[_name]
    
    if _hand == nil then
        print("Could not find player named: " .. _name )
        return false
    end
    
    print("")
    print("[".._name.."] was dealt:")
    for index, card in ipairs(_hand) do
        printCard( card )
    end
    
    if _hand.outcome ~= nil and _hand.outcome ~= false then
        print( "-> result: ".. _hand.outcome.name )
    end
    
end









#! /usr/bin/ruby

def is_js(str)
  !!str.match(/^(.*)\.js$/)
end

%w{one two.css three.rb four.js dir/ }.each do |str|
 puts "is #{str} a js file string: #{is_js( str )}"
end


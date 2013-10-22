; BFS.lisp
; Author: Danny Hadley


; trace-lineage
; - called on the list of states that were placed in the closed list
; - to find the touple that belongs to the state passed in. 
(defun trace-lineage (state list)
  	(cond 
		((null list) nil)
        	((equal state (get-state (car list))) (car list))
        	(t (trace-lineage state (cdr list)))
	)
)

; trace-solution
; - called on completion of matching the current state to the final state
; - and will recursively cycle through the tree finding parent-child matches
(defun trace-solution (state)
	(cond 
		((null state) nil)
        	(t (cons 
			state 
			(trace-solution (get-parent (trace-lineage state *closed*)))
		))
	)
)

; first-instance
; - checks to make sure the state in question is not in the "closed" list
(defun first-instance (state past-states)
	(cond
		((null state) nil)
		((null past-states) t)
		((equal state (get-state (car past-states))) nil)
		(t (first-instance state (cdr past-states)))
	)
)

(defun find-moves (state)
	(let (
		(possibles ())
		(farmer-moved (funcall (nth 0 *moves*) state))
		(wolf-moved (funcall (nth 1 *moves*) state))
		(goat-moved (funcall (nth 2 *moves*) state))
		(cabbage-moved (funcall (nth 3 *moves*) state)))
		(cond ((first-instance farmer-moved *closed*)
			(cond ((first-instance farmer-moved *open*)
			(setq possibles (append possibles 
				(list (build-record farmer-moved state))))))
		))
		(cond ((first-instance wolf-moved *closed*) 
			(cond ((first-instance wolf-moved *open*)
			(setq possibles (append possibles 
				(list (build-record wolf-moved state))))))
		))
		(cond ((first-instance goat-moved *closed*) 
			(cond ((first-instance goat-moved *open*)
			(setq possibles (append possibles 
				(list (build-record goat-moved state))))))
		))
		(cond ((first-instance cabbage-moved *closed*)
			(cond ((first-instance cabbage-moved *open*)
			(setq possibles (append possibles 
				(list (build-record cabbage-moved state))))))
		))
		possibles
	)
)

; breadth-first 
; - the function that iterates all possibilites 
(defun breadth-first ()
	(cond 
		((equal *open* nil) nil)
		(t (let ((current-record (car *open*)))
			(setq *closed* (cons current-record *closed*))
			(let ((current-state (get-state current-record)))
			(cond
				; the current state and the goal are equal - back out
				((equal current-state *goal*) (reverse (trace-solution *goal*)))
				; traverse down the tree
				(t 
				(setq *open* 
				(append (cdr *open*) (find-moves current-state))
				)
				(breadth-first)
				)
			))
		))
	)
)

; run-breadth 
; - the starting point for the farmer puzzle
(defun run-breadth (start end)
	(setq *open* (list (build-record start nil)))
	(setq *closed* nil)
	(setq *goal* end)
	(setq *moves* '(bring-self bring-wolf bring-goat bring-cabbage))
	(breadth-first)
)

; build-record
; - builds a list of a state and links it to it's parent
(defun build-record (state parent)
	(list state parent)
)

; getter methods for working with the (state parent) data structure
(defun get-state (record) 
	(car record)
)
(defun get-parent (record)
	(nth 1 record)
)



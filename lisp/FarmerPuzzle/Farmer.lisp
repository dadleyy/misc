; Farmer.lisp 
; Author: Danny Hadley


; validity checker for a state
(defun valid (state)
	(cond 
		; if the farmer is not with the wolf
		((equal nil (equal (farmer-pos state) (wolf-pos state)))
			; check the goat and the wolf
			(cond
				((equal (wolf-pos state) (goat-pos state)) nil)
				(t state)
			)
			
		)
		; if the farmer is not with the goat
		((equal nil (equal (farmer-pos state) (goat-pos state)))
			; check the goat and the cabbage 
			(cond
				((equal (goat-pos state) (cabbage-pos state)) nil)
				(t state)
			)
		)
		(t state)
	)
)


; mover methods for states
(defun bring-wolf (state)
	(cond 
		((equal (farmer-pos state) (wolf-pos state)) 
			(valid (list
				(toggle (farmer-pos state))
				(toggle (wolf-pos state))
				(goat-pos state)
				(cabbage-pos state)
			))
		)
		(t nil)
	)
)

(defun bring-goat (state)
	(cond
		((equal (farmer-pos state) (goat-pos state))
			(valid (list 
				(toggle (farmer-pos state))
				(wolf-pos state)
				(toggle (goat-pos state))
				(cabbage-pos state)
			))
		)
		(t nil)
	)
)

(defun bring-cabbage (state)
	(cond 
		((equal (farmer-pos state) (goat-pos state))
			(valid (list
				(toggle (farmer-pos state))
				(wolf-pos state)
				(goat-pos state)
				(toggle (cabbage-pos state))
			))
		)
		(t nil)
	)
)

(defun bring-self (state)
	(valid (list 
		(toggle (farmer-pos state))
		(wolf-pos state)
		(goat-pos state)
		(cabbage-pos state)
	))
)
				

; toggle method for state 
(defun toggle (value)
	(cond 
		((equal value 'w) 'e)
		((equal value 'e) 'w)
		(t nil)
	)
)

; getter methods for the states of the participants
(defun farmer-pos (state)
	(nth 0 state)
)
(defun wolf-pos (state)
	(nth 1 state)
)
(defun goat-pos (state)
	(nth 2 state)
)
(defun cabbage-pos (state)
	(nth 3 state)
)

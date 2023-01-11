/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:13:03 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/11 18:13:06 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_DEFINES_H
# define SL_DEFINES_H

# define ERROR_MALLOC			"Memory allocation failed."

# define ERROR_MAP_EXTENSION	"Wrong map extension."
# define ERROR_EMPTY_FILE		"Empty file."

# define ERROR_BAD_MAP_SHAPE	"Map has not a regular shape."
# define ERROR_BOTTOM_WALL		"Invalid character in bottom wall."
# define ERROR_TOP_WALL			"Invalid character in top wall."
# define ERROR_SIDE_WALL 		"Invalid character in side wall."
# define ERROR_INVALID_CHAR 	"Invalid char in map."

# define ERROR_COLLECT_COUNT 	"Amount of collectibles is 0."
# define ERROR_PLAYER_COUNT		"Amount of Player starting position is not 1."
# define ERROR_EXIT_COUNT 		"Amount of Exit point is not 1."
# define ERROR_INVALID_MAP		"Invalid map, exit or collectibles not \
reachable"

#endif